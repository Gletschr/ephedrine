//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: src/internal/Array.cpp
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

#include "internal/Log.h"
#include "internal/Array.h"
#include "internal/Context.h"
#include "internal/TypeInfo.h"

//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	
	Array::Array(
		Ephedrine::Type type, size_t size, Context *context, cl_mem mem) : 
		Ephedrine::Array(type, size), context(context), mem(mem) { }
	
	//-------------------------------------------------------------------------
	
	Array::~Array() {
		cl_int result = clReleaseMemObject(mem);
		if(result != CL_SUCCESS)
			Log::error("an error occured while removing array. "
				"OpenCL error code: %i.", result);
	}
	
	//-------------------------------------------------------------------------
	
	bool Array::getRawData(
		uint8_t *buffer, size_t offset, size_t count) {
		
		EPHEDRINE_ASSERT(offset + count <= TypeInfo(type).size * size,
			"Data index out of range.");
		return context->readMemory(mem, buffer, offset, count);
	}
	
	//-------------------------------------------------------------------------

	bool Array::setRawData(
		const uint8_t *buffer, size_t offset, size_t count) {
		
		EPHEDRINE_ASSERT(offset + count <= TypeInfo(type).size * size,
			"Data index out of range.");
		return context->writeMemory(mem, buffer, offset, count);
	}
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------