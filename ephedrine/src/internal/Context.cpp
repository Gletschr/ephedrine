//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: src/internal/Context.cpp
//
// Author: Kostarev Georgy
// E-Mail: kostarevgi@gmail.com
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// License: MIT (opensource.org/licenses/MIT)
//
// Copyright © 2017 Kostarev Georgy
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
// DEALINGS IN THE SOFTWARE.
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

#include <malloc.h>
#include <cstring>

//-----------------------------------------------------------------------------

#include "internal/Log.h"
#include "internal/Array.h"
#include "internal/Context.h"
#include "internal/TypeInfo.h"

//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	
	Context::Context(
		cl_device_id device, cl_context context, cl_command_queue queue) :
		device(device), context(context), queue(queue), kernels(nullptr) { }
	
	//-------------------------------------------------------------------------
	
	Context::~Context() {
		cl_int result = clReleaseCommandQueue(queue);
		if(result != CL_SUCCESS)
			Log::error("an error occured while removing context. "
				"OpenCL error code: %i.", result);
		result = clReleaseContext(context);
		if(result != CL_SUCCESS)
			Log::error("an error occured while removing context. "
				"OpenCL error code: %i.", result);
		result = clReleaseDevice(device);
		if(result != CL_SUCCESS)
			Log::error("an error occured while removing context. "
				"OpenCL error code: %i.", result);
		free(kernels);
	}
	
	//-------------------------------------------------------------------------
	
	struct Source {
		Program i;
		const char *name;
		const char *data;
	};
	
	//-------------------------------------------------------------------------

	#define EPHEDRINE_KERNEL_USE_FP64  \
	#pragma OPENCL EXTENSION cl_khr_fp64: enable
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_A_UOP(n, t, o, ...) \
	{ \
	Program:: n, \
	#n, \
	#__VA_ARGS__ \
	"\n" \
	"__kernel void " #n \
	"(" \
	"__global " #t "*a" \
	")" \
	"{" \
	"int i = get_global_id(0);" \
	#o " a[i];" \
	"}" \
	}
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_A_UOP_INC(n, t, ...) \
	EPHEDRINE_KERNEL_A_UOP(EPH_A_Inc_ ## n, t, ++, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_UOP_DEC(n, t, ...) \
	EPHEDRINE_KERNEL_A_UOP(EPH_A_Dec_ ## n, t, --, __VA_ARGS__)
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_A_UOP_EXT(m) \
	m(Char, char), \
	m(UChar, uchar), \
	m(Short, short), \
	m(UShort, ushort), \
	m(Int, int), \
	m(UInt, uint), \
	m(Long, long), \
	m(ULong, ulong), \
	m(Float, float), \
	m(Double, double, EPHEDRINE_KERNEL_USE_FP64)
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_AA_BOP(n, t, o, ...) \
	{ \
	Program:: n, \
	#n, \
	#__VA_ARGS__ \
	"\n" \
	"__kernel void " #n \
	"(" \
	"__global " #t "*a" \
	"," \
	"__global " #t "*b" \
	"," \
	"__global " #t "*r" \
	")" \
	"{" \
	"int i = get_global_id(0);" \
	"r[i] = a[i] " #o " b[i];" \
	"}" \
	}
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_AA_BOP_ADD(n, t, ...) \
	EPHEDRINE_KERNEL_AA_BOP(EPH_AA_Add_ ## n, t, +, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_AA_BOP_SUB(n, t, ...) \
	EPHEDRINE_KERNEL_AA_BOP(EPH_AA_Sub_ ## n, t, -, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_AA_BOP_MUL(n, t, ...) \
	EPHEDRINE_KERNEL_AA_BOP(EPH_AA_Mul_ ## n, t, *, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_AA_BOP_DIV(n, t, ...) \
	EPHEDRINE_KERNEL_AA_BOP(EPH_AA_Div_ ## n, t, /, __VA_ARGS__)

	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_AA_BOP_EXT(m) \
	m(Char, char), \
	m(UChar, uchar), \
	m(Short, short), \
	m(UShort, ushort), \
	m(Int, int), \
	m(UInt, uint), \
	m(Long, long), \
	m(ULong, ulong), \
	m(Float, float), \
	m(Double, double, EPHEDRINE_KERNEL_USE_FP64)
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_A_FN1(n, t, f, ...) \
	{ \
	Program:: n, \
	#n, \
	#__VA_ARGS__ \
	"\n" \
	"__kernel void " #n \
	"(" \
	"__global " #t "*a" \
	"," \
	"__global " #t "*r" \
	")" \
	"{" \
	"int i = get_global_id(0);" \
	"r[i] = " #f "(a[i]);" \
	"}" \
	}
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_A_FN1_COS(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Cos_ ## n, t, cos, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_SIN(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Sin_ ## n, t, sin, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_TAN(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Tan_ ## n, t, tan, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_ACOS(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Acos_ ## n, t, acos, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_ASIN(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Asin_ ## n, t, asin, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_ATAN(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Atan_ ## n, t, atan, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_CBRT(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Cbrt_ ## n, t, cbrt, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_CEIL(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Ceil_ ## n, t, ceil, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_ERF(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Erf_ ## n, t, erf, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_ERFC(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Erfc_ ## n, t, erfc, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_EXP(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Exp_ ## n, t, exp, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_EXP2(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Exp2_ ## n, t, exp2, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_EXP10(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Exp10_ ## n, t, exp10, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_FABS(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Fabs_ ## n, t, fabs, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_FLOOR(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Floor_ ## n, t, floor, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_LOG(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Log_ ## n, t, log, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_LOG2(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Log2_ ## n, t, log2, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_LOG10(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Log10_ ## n, t, log10, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_TRUNC(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Trunc_ ## n, t, trunc, __VA_ARGS__)
	
	#define EPHEDRINE_KERNEL_A_FN1_ROUND(n, t, ...) \
	EPHEDRINE_KERNEL_A_FN1(EPH_A_Round_ ## n, t, round, __VA_ARGS__)
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_A_FN1_EXT(m) \
	m(Float, float), \
	m(Double, double, EPHEDRINE_KERNEL_USE_FP64)
	
	//-------------------------------------------------------------------------
	
	bool Context::compile() {
		
		Source sources[] = {
			
			EPHEDRINE_KERNEL_A_UOP_EXT(EPHEDRINE_KERNEL_A_UOP_INC),
			EPHEDRINE_KERNEL_A_UOP_EXT(EPHEDRINE_KERNEL_A_UOP_DEC),
			
			EPHEDRINE_KERNEL_AA_BOP_EXT(EPHEDRINE_KERNEL_AA_BOP_ADD),
			EPHEDRINE_KERNEL_AA_BOP_EXT(EPHEDRINE_KERNEL_AA_BOP_SUB),
			EPHEDRINE_KERNEL_AA_BOP_EXT(EPHEDRINE_KERNEL_AA_BOP_MUL),
			EPHEDRINE_KERNEL_AA_BOP_EXT(EPHEDRINE_KERNEL_AA_BOP_DIV),
			
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_COS),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_SIN),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_TAN),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_ACOS),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_ASIN),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_ATAN),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_CBRT),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_CEIL),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_ERF),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_ERFC),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_EXP),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_EXP2),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_EXP10),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_FABS),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_FLOOR),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_LOG),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_LOG2),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_LOG10),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_TRUNC),
			EPHEDRINE_KERNEL_A_FN1_EXT(EPHEDRINE_KERNEL_A_FN1_ROUND),
			
		};
		
		constexpr size_t size = 
			sizeof(sources) / sizeof(Source);
		
		kernels = (cl_kernel *)(malloc(size * sizeof(cl_kernel)));
		memset(kernels, 0, size * sizeof(cl_kernel));
		
		cl_int result;
		for(size_t i = 0; i < size; ++ i) {
			EPHEDRINE_ASSERT(kernels[sources[i].i] == nullptr,
				"Kernel data overwrite.");
			cl_program program = clCreateProgramWithSource(
				context, 1, &sources[i].data, nullptr, &result);
			if(result != CL_SUCCESS) {
				Log::error("compiling kernel (%zi/%zi) \"%s\": fail. "
					"OpenCL error code: %i.", 
					i + 1, size, sources[i].name, result);
				continue;
			}
			result = clBuildProgram(
				program, 1, &device, nullptr, nullptr, nullptr);
			if(result != CL_SUCCESS) {
				Log::error("compiling kernel (%zi/%zi) \"%s\": fail. "
					"OpenCL error code: %i.", 
					i + 1, size, sources[i].name, result);
				continue;
			}
			kernels[sources[i].i] = clCreateKernel(
				program, sources[i].name, &result);
			if(result != CL_SUCCESS) {
				Log::error("compiling kernel (%zi/%zi) \"%s\": fail. "
					"OpenCL error code: %i.", 
					i + 1, size, sources[i].name, result);
				continue;
			}
			Log::success("compiling kernel "
				"(%zi/%zi) \"%s\": success.", i + 1, size, sources[i].name);
		}
		
		return true;
		
	}
	
	//-------------------------------------------------------------------------
	
	bool Context::runProgram(
		Program program, size_t range, cl_uint argc, cl_mem *argv) {
		
		EPHEDRINE_ASSERT(range > 0, 
			"Range should be greater than zero.");
		cl_kernel kernel = kernels[program];
		if(kernel == nullptr) {
			Log::error("an error occured while executing program %i. "
				"Program is unavailable on current device.", program);
			return false;
		}
		cl_int result;
		for(cl_uint i = 0; i < argc; ++ i) {
			result = clSetKernelArg(
				kernel, i, sizeof(cl_mem), (void *)&argv[i]);
			if(result != CL_SUCCESS) {
				Log::error("an error occured while executing program %i. "
					"OpenCL error code: %i.", program, result);
				return false;
			}
		}
		result = clEnqueueNDRangeKernel(
			queue, kernel, 1, nullptr, &range, nullptr, 0, nullptr, nullptr);
		if(result != CL_SUCCESS)
			Log::error("an error occured while executing program %i. "
				"OpenCL error code: %i.", program, result);
		return result == CL_SUCCESS;
	}
	
	//-------------------------------------------------------------------------
	
	bool Context::readMemory(
		cl_mem mem, uint8_t *buffer, size_t offset, size_t count) {
		
		cl_int result = clEnqueueReadBuffer(
			queue, mem, CL_TRUE, offset, 
			count, buffer, 0, nullptr, nullptr);
		if(result != CL_SUCCESS)
			Log::error("an error occured while reading memory object. "
				"OpenCL error code: %i.", result);
		return result == CL_SUCCESS;
	}
	
	//-------------------------------------------------------------------------
	
	bool Context::writeMemory(
		cl_mem mem, const uint8_t *buffer, size_t offset, size_t count) {
		
		cl_int result = clEnqueueWriteBuffer(
			queue, mem, CL_TRUE, offset, 
			count, buffer, 0, nullptr, nullptr);
		if(result != CL_SUCCESS)
			Log::error("an error occured while reading memory object. "
				"OpenCL error code: %i.", result);
		return result == CL_SUCCESS;
	}
	
	//-------------------------------------------------------------------------
	
	Ephedrine::Array *Context::createArray(Ephedrine::Type type, size_t size) {
		EPHEDRINE_ASSERT(size > 0, 
			"Array size should be greater than zero.");
		size_t size_in_bytes = TypeInfo(type).size * size;
		cl_int result;
		cl_mem mem = clCreateBuffer(
			context, CL_MEM_READ_WRITE, size_in_bytes, NULL, &result);
		if(result != CL_SUCCESS) {
			Log::error("an error occured while creating array. "
				"OpenCL error code: %i.", result);
			return nullptr;
		}
		return new Array(type, size, this, mem);
	}
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------