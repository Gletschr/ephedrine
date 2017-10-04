//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/internal/Context.h
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

#ifndef __EPHEDRINE_CONTEXT_INTERNAL_H__
#define __EPHEDRINE_CONTEXT_INTERNAL_H__

//-----------------------------------------------------------------------------

#include <CL/cl.h>

//-----------------------------------------------------------------------------

#include "EphedrineContext.h"

//-----------------------------------------------------------------------------

#include "internal/Program.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Ephedrine API internal namespace.
//
//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	//
	// Context implementation class.
	//
	//-------------------------------------------------------------------------
	
	class Context : public Ephedrine::Context {
			
			cl_kernel *kernels;		// OpenCL kernels.
			cl_context context;		// OpenCL context.
			cl_device_id device;	// OpenCL device ID.
			cl_command_queue queue;	// OpenCL command queue.			
			
		public:
			
			//-----------------------------------------------------------------
			//
			// Constructor.
			//
			// device 	OpenCL device ID.
			// context 	OpenCL context.
			// queue 	OpenCL command queue.
			//
			//-----------------------------------------------------------------
		
			Context(cl_device_id device, 
				cl_context context, cl_command_queue queue);
			
			//-----------------------------------------------------------------
			//
			// Destructor.
			//
			//-----------------------------------------------------------------
		
			virtual ~Context();
			
			//-----------------------------------------------------------------
			//
			// Compile kernels.
			//
			// Returns true on success, false - otherwise.
			//
			//-----------------------------------------------------------------
			
			bool compile();
			
			//-----------------------------------------------------------------
			//
			// Run program.
			//
			// program 	Program type.
			// range 	OpenCL kernel work size.
			// argc 	Arguments count.
			// argv 	Arguments memory objects.
			//
			// Returns true on success, false - otherwise.
			//
			//-----------------------------------------------------------------
			
			bool runProgram(
				Program program, size_t range, size_t argc, cl_mem *argv);
			
			//-----------------------------------------------------------------
			//
			// Read raw data from memory.
			//
			// mem		Memory object.
			// buffer 	Destignation buffer.
			// offset 	Memory offset in bytes.
			// count 	Num bytes to read.
			//
			// Returns true on readed succesfully, false - otherwise.
			//
			//-----------------------------------------------------------------
			
			bool readMemory(cl_mem mem, 
				uint8_t *buffer, size_t offset, size_t count);
			
			//-----------------------------------------------------------------
			//
			// Write raw data to memory.
			//
			// buffer 	Source buffer.
			// offset 	Memory offset in bytes.
			// count 	Num bytes to write.
			//
			// Returns true on writed succesfully, false - otherwise.
			//
			//-----------------------------------------------------------------
			
			bool writeMemory(cl_mem mem, 
				const uint8_t *buffer, size_t offset, size_t count);
				
			//-----------------------------------------------------------------
			//
			// Create an array.
			//
			// type 	Array data type.
			// size 	Array elements count.
			//
			// Returns array pointer on success, nullptr - otherwise.
			//
			//-----------------------------------------------------------------
			
			virtual Ephedrine::Array *createArray(
				Ephedrine::Type type, size_t size) override final;
			
			//-----------------------------------------------------------------
		
	};

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_CONTEXT_INTERNAL_H__

//-----------------------------------------------------------------------------