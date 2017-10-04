//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/internal/TypeInfo.h
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

#ifndef __EPHEDRINE_TYPE_INFO_INTERNAL_H__
#define __EPHEDRINE_TYPE_INFO_INTERNAL_H__

//-----------------------------------------------------------------------------

#include "EphedrineType.h"

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//
// Ephedrine API internal namespace.
//
//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	//
	// Type information struct.
	//
	//-------------------------------------------------------------------------
	
	struct TypeInfo {
		
		size_t size;		// Type size.
		const char *name;	// Type name.
		
		//---------------------------------------------------------------------
		//
		// Constructor.
		//
		// type 	Data type.
		//
		//---------------------------------------------------------------------
		
		TypeInfo(Ephedrine::Type type);
		
		//---------------------------------------------------------------------
		//
		// Constructor.
		//
		// type_info	Type information.
		//
		//---------------------------------------------------------------------
		
		TypeInfo(const TypeInfo &type_info);
		
		//---------------------------------------------------------------------
		//
		// Assignment operator.
		//
		// type_info 	Type information.
		//
		//---------------------------------------------------------------------
		
		TypeInfo &operator=(const TypeInfo &type_info);
		
		//---------------------------------------------------------------------
		
	};

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_TYPE_INFO_INTERNAL_H__

//-----------------------------------------------------------------------------