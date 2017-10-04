//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/EphedrineContext.h
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

#ifndef __EPHEDRINE_CONTEXT_H__
#define __EPHEDRINE_CONTEXT_H__

//-----------------------------------------------------------------------------

#include "EphedrineType.h"
#include "EphedrineDevice.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Ephedrine API namespace.
//
//-----------------------------------------------------------------------------

namespace Ephedrine {
	
	//-------------------------------------------------------------------------
	//
	// Array class forward declaration.
	//
	//-------------------------------------------------------------------------
	
	class Array;
	
	//-------------------------------------------------------------------------
	//
	// Context interface class.
	//
	//-------------------------------------------------------------------------
	
	class EPHEDRINE_API Context {
		
		public:
			
			//-----------------------------------------------------------------
			//
			// Destructor.
			//
			//-----------------------------------------------------------------
		
			virtual ~Context();
			
			//-----------------------------------------------------------------
			//
			// Constructor.
			//
			// device 	Target device type.
			//
			// Returns context pointer on success, nullptr - otherwise.
			//
			//-----------------------------------------------------------------
			
			static Context *create(Device device);
			
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
			
			virtual Array *createArray(Type type, size_t size) = 0;
			
			//-----------------------------------------------------------------
		
	};

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_CONTEXT_H__

//-----------------------------------------------------------------------------