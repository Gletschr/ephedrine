//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/internal/Array.h
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

#ifndef __EPHEDRINE_ARRAY_INTERNAL_H__
#define __EPHEDRINE_ARRAY_INTERNAL_H__

//-----------------------------------------------------------------------------

#include <CL/cl.h>

//-----------------------------------------------------------------------------

#include "EphedrineArray.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Ephedrine API internal namespace.
//
//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	//
	// Context class forward declaration.
	//
	//-------------------------------------------------------------------------
	
	class Context;
	
	//-------------------------------------------------------------------------
	//
	// Array implementation class.
	//
	//-------------------------------------------------------------------------
	
	class Array : public Ephedrine::Array {
			
			cl_mem mem; 		// OpenCL memory object.
			Context *context; 	// Array owner context.
			
		public:
		
			//-----------------------------------------------------------------
			//
			// Constructor.
			//
			// type 	Array data type.
			// size 	Array elements count.
			// context 	Array owner context.
			// mem 		OpenCL memory object.
			//
			//-----------------------------------------------------------------
			
			Array(Ephedrine::Type type, 
				size_t size, Context *context, cl_mem mem);
			
			//-----------------------------------------------------------------
			//
			// Destructor.
			//
			//-----------------------------------------------------------------
			
			virtual ~Array();
			
			//-----------------------------------------------------------------
			//
			// Get array memory object.
			//
			// Returns array memory object.
			//
			//-----------------------------------------------------------------
			
			cl_mem getMemory() const { return mem; }
			
			//-----------------------------------------------------------------
			//
			// Get array owner context.
			//
			// Returns array owner context pointer.
			//
			//-----------------------------------------------------------------
			
			Context *getContext() { return context; }
			
			//-----------------------------------------------------------------
			//
			// Read raw data from array.
			//
			// buffer 	Destignation buffer.
			// offset 	Array offset in bytes.
			// count 	Num bytes to read.
			//
			// Returns true on readed succesfully, false - otherwise.
			//
			//-----------------------------------------------------------------
			
			virtual bool getRawData(uint8_t *buffer, 
				size_t offset, size_t count) override final;
			
			//-----------------------------------------------------------------
			//
			// Write raw data to an array.
			//
			// buffer 	Source buffer.
			// offset 	Array offset in bytes.
			// count 	Num bytes to write.
			//
			// Returns true on writed succesfully, false - otherwise.
			//
			//-----------------------------------------------------------------
			
			virtual bool setRawData(const uint8_t *buffer, 
				size_t offset, size_t count) override final;
			
			//-----------------------------------------------------------------
		
	};

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_ARRAY_INTERNAL_H__

//-----------------------------------------------------------------------------