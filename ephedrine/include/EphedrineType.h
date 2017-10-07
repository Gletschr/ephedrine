//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/EphedrineType.h
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

#ifndef __EPHEDRINE_TYPE_H__
#define __EPHEDRINE_TYPE_H__

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
	// Data type enumerator class.
	//
	//-------------------------------------------------------------------------
	
	enum EPHEDRINE_API Type {
		
		EPH_Char	= 0x00, // char
		EPH_UChar	= 0x01, // unsigned char
		EPH_Short	= 0x02, // short
		EPH_UShort	= 0x03, // unsigned short
		EPH_Int		= 0x04, // int
		EPH_UInt	= 0x05, // unsigned int
		EPH_Long	= 0x06, // long
		EPH_ULong	= 0x07, // unsigned long
		EPH_Float	= 0x08, // float
		EPH_Double	= 0x09, // double
		
	};
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_TYPE_H__

//-----------------------------------------------------------------------------