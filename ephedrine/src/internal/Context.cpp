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
		const char *name;
		const char *data;
	};
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_KERNEL_AA_MATH(n, t, o) \
	{ \
	#n, \
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
	
	#define EPHEDRINE_KERNEL_AA_MATH_ADD(n, t) \
	EPHEDRINE_KERNEL_AA_MATH(n, t, +)
	
	#define EPHEDRINE_KERNEL_AA_MATH_SUB(n, t) \
	EPHEDRINE_KERNEL_AA_MATH(n, t, -)
	
	#define EPHEDRINE_KERNEL_AA_MATH_MUL(n, t) \
	EPHEDRINE_KERNEL_AA_MATH(n, t, *)
	
	#define EPHEDRINE_KERNEL_AA_MATH_DIV(n, t) \
	EPHEDRINE_KERNEL_AA_MATH(n, t, /)
	
	//-------------------------------------------------------------------------
	
	bool Context::compile() {
		
		Source sources[] = {
			
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_Char, char),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_UChar, uchar),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_Short, short),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_UShort, ushort),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_Int, int),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_UInt, uint),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_Long, long),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_ULong, ulong),
			EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_Float, float),
			// EPHEDRINE_KERNEL_AA_MATH_ADD(EPH_AA_Add_Double, double),
			
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_Char, char),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_UChar, uchar),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_Short, short),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_UShort, ushort),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_Int, int),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_UInt, uint),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_Long, long),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_ULong, ulong),
			EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_Float, float),
			// EPHEDRINE_KERNEL_AA_MATH_SUB(EPH_AA_Sub_Double, double),
			
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_Char, char),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_UChar, uchar),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_Short, short),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_UShort, ushort),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_Int, int),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_UInt, uint),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_Long, long),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_ULong, ulong),
			EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_Float, float),
			// EPHEDRINE_KERNEL_AA_MATH_MUL(EPH_AA_Mul_Double, double),
			
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_Char, char),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_UChar, uchar),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_Short, short),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_UShort, ushort),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_Int, int),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_UInt, uint),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_Long, long),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_ULong, ulong),
			EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_Float, float),
			// EPHEDRINE_KERNEL_AA_MATH_DIV(EPH_AA_Div_Double, double),
			
		};
		
		constexpr size_t size = 
			sizeof(sources) / sizeof(Source);
		
		kernels = (cl_kernel *)(malloc(size * sizeof(cl_kernel)));
		
		cl_int result;
		for(size_t i = 0; i < size; ++ i) {
			cl_program program = clCreateProgramWithSource(
				context, 1, &sources[i].data, nullptr, &result);
			if(result != CL_SUCCESS) {
				Log::error("an error occured while compiling kernels. "
					"OpenCL error code: %i.", result);
				return false;
			}
			result = clBuildProgram(
				program, 1, &device, nullptr, nullptr, nullptr);
			if(result != CL_SUCCESS) {
				Log::error("an error occured while compiling kernels. "
					"OpenCL error code: %i.", result);
				return false;
			}
			kernels[i] = clCreateKernel(
				program, sources[i].name, &result);
			if(result != CL_SUCCESS) {
				Log::error("an error occured while compiling kernels. "
					"OpenCL error code: %i.", result);
				return false;
			}
		}
		
		return true;
		
	}
	
	//-------------------------------------------------------------------------
	
	bool Context::runProgram(
		Program program, size_t range, size_t argc, cl_mem *argv) {
		cl_kernel kernel = kernels[program];
		cl_int result;
		for(size_t i = 0; i < argc; ++ i) {
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