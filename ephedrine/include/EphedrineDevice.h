//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/EphedrineDevice.h
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

#ifndef __EPHEDRINE_DEVICE_H__
#define __EPHEDRINE_DEVICE_H__

//-----------------------------------------------------------------------------

#include "EphedrineOsDefs.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Ephedrine API namespace.
//
//-----------------------------------------------------------------------------

namespace Ephedrine {
	
	//-------------------------------------------------------------------------
	//
	// Device type enumerator class.
	//
	//-------------------------------------------------------------------------
	
	enum EPHEDRINE_API Device {
		
		EPH_CPU_0	= 0x00, // CPU 0
		EPH_CPU_1	= 0x01, // CPU 1
		EPH_CPU_2	= 0x02, // CPU 2
		EPH_CPU_3	= 0x03, // CPU 3
		
		EPH_GPU_0	= 0x04, // GPU 0
		EPH_GPU_1	= 0x05, // GPU 1
		EPH_GPU_2	= 0x06, // GPU 2
		EPH_GPU_3	= 0x07, // GPU 3
		
	};
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_DEVICE_H__

//-----------------------------------------------------------------------------