//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: src/EphedrineContext.cpp
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

#include "EphedrineContext.h"

//-----------------------------------------------------------------------------

#include "internal/Log.h"
#include "internal/Context.h"

//-----------------------------------------------------------------------------

namespace Ephedrine {
	
	//-------------------------------------------------------------------------
	
	Context::~Context() { }
	
	//-------------------------------------------------------------------------
	
	Context *Context::create(Device device) {
		cl_platform_id platform;
		cl_int result = clGetPlatformIDs(1, &platform, nullptr);
		if(result != CL_SUCCESS) {
			Internal::Log::error(
				"unable to get platform. OpenCL error code: %i.", result);
			return nullptr;
		}
		size_t i = 0;
		cl_device_type type;
		switch(device) {
		case Device::EPH_CPU_0:
		case Device::EPH_CPU_1:
		case Device::EPH_CPU_2:
		case Device::EPH_CPU_3:
			type = CL_DEVICE_TYPE_CPU;
			i = device - Device::EPH_CPU_0;
			break;
		case Device::EPH_GPU_0:
		case Device::EPH_GPU_1:
		case Device::EPH_GPU_2:
		case Device::EPH_GPU_3:
			type = CL_DEVICE_TYPE_GPU;
			i = device - Device::EPH_GPU_0;
			break;
		default:
			Internal::Log::error("undefined device %i.", device);
			return nullptr;
		}
		size_t c = 0;
		cl_device_id devices[4];
		result = clGetDeviceIDs(platform, type, 
			sizeof(devices) / sizeof(devices[0]), devices, &c);
		if(result != CL_SUCCESS) {
			Internal::Log::error("unable to get devices. "
				"OpenCL error code: %i.", result);
			return nullptr;
		}
		if(c == 0) {
			Internal::Log::error("device with given type not found.");
			return nullptr;
		}
		if(i >= c) {
			Internal::Log::warning("device with index %i is unavailable. "
				"Using device with index %i.", i, 0);
			i = 0;
		}
		cl_device_id dev = devices[i];		
		cl_context ctx = clCreateContext(
			nullptr, 1, &dev, nullptr, nullptr, &result);
		if(result != CL_SUCCESS) {
			Internal::Log::error("an error occured while creating context. "
				"OpenCL error code: %i.", result);
			return nullptr;
		}
		cl_command_queue queue = 
			clCreateCommandQueueWithProperties(ctx, dev, 0, &result);
		if(result != CL_SUCCESS) {
			Internal::Log::error("an error occured while creating context. "
				"OpenCL error code: %i.", result);
			return nullptr;
		}
		Internal::Context *context = new Internal::Context(dev, ctx, queue);
		if(!context->compile()) {
			Internal::Log::error("unable to compile context.");
			delete context;
			return nullptr;
		}
		return context;
	}
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------