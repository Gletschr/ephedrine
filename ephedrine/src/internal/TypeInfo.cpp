//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: src/internal/TypeInfo.cpp
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

#include <CL/cl.h>

//-----------------------------------------------------------------------------

#include "internal/TypeInfo.h"

//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	
	TypeInfo::TypeInfo(Ephedrine::Type type) {
		switch(type) {
		case Ephedrine::Type::EPH_Char:
			name = "char";
			size = sizeof(cl_char);
			break;
		case Ephedrine::Type::EPH_UChar: 
			name = "uchar";
			size = sizeof(cl_uchar);
			break;
		case Ephedrine::Type::EPH_Short: 
			name = "short";
			size = sizeof(cl_short);	
			break;
		case Ephedrine::Type::EPH_UShort: 
			name = "ushort";
			size = sizeof(cl_ushort);
			break;
		case Ephedrine::Type::EPH_Int: 
			name = "int";
			size = sizeof(cl_int);
			break;
		case Ephedrine::Type::EPH_UInt: 
			name = "uint";
			size = sizeof(cl_uint);
			break;
		case Ephedrine::Type::EPH_Long: 
			name = "long";
			size = sizeof(cl_long);
			break;
		case Ephedrine::Type::EPH_ULong: 
			name = "ulong";
			size = sizeof(cl_ulong);
			break;				
		case Ephedrine::Type::EPH_Float: 
			name = "float";
			size = sizeof(cl_float);
			break;
		case Ephedrine::Type::EPH_Double: 
			name = "double";
			size = sizeof(cl_double);
			break;
		default:
			name = "undefined";
			size = 0;
			EPHEDRINE_ASSERT(false, "Undefined Ephedrine::Type value.");
		}
	}
	
	//-------------------------------------------------------------------------
	
	TypeInfo::TypeInfo(const TypeInfo &type_info) : 
		name(type_info.name), size(type_info.size) { }
	
	//-------------------------------------------------------------------------
	
	TypeInfo &TypeInfo::operator=(const TypeInfo &type_info) {
		name = type_info.name;
		size = type_info.size;
		return *this;
	}
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------