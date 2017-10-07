//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: src/EphedrineMath.cpp
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

#include "EphedrineMath.h"
#include "EphedrineArray.h"

//-----------------------------------------------------------------------------

#include "internal/Log.h"
#include "internal/Array.h"
#include "internal/Context.h"

//-----------------------------------------------------------------------------

namespace Ephedrine {
	
	//-------------------------------------------------------------------------
	
	namespace Math {
		
		//---------------------------------------------------------------------
		
		bool add(Array *a, Array *b, Array *result) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Internal::Array *i_b = (Internal::Array *)(b);
			Internal::Array *i_result = (Internal::Array *)(result);
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			if(	i_b->getType() != type ||
				i_result->getType() != type ||
				i_b->getSize() != size ||
				i_result->getSize() != size ||
				i_b->getContext() != context ||
				i_result->getContext() != context) {
				Internal::Log::error(
					"(Math::add) invalid array type/size/context.");
				return false;
			}
			cl_mem mem[3] = {
				i_a->getMemory(),
				i_b->getMemory(),
				i_result->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Char:
				program = Internal::Program::EPH_AA_Add_Char;
				break;
			case Type::EPH_UChar:
				program = Internal::Program::EPH_AA_Add_UChar;
				break;
			case Type::EPH_Short:
				program = Internal::Program::EPH_AA_Add_Short;
				break;
			case Type::EPH_UShort:
				program = Internal::Program::EPH_AA_Add_UShort;
				break;
			case Type::EPH_Int:
				program = Internal::Program::EPH_AA_Add_Int;
				break;
			case Type::EPH_UInt:
				program = Internal::Program::EPH_AA_Add_UInt;
				break;
			case Type::EPH_Long:
				program = Internal::Program::EPH_AA_Add_Long;
				break;
			case Type::EPH_ULong:
				program = Internal::Program::EPH_AA_Add_ULong;
				break;
			case Type::EPH_Float:
				program = Internal::Program::EPH_AA_Add_Float;
				break;
			case Type::EPH_Double:
				program = Internal::Program::EPH_AA_Add_Double;
				break;
			default:
				Internal::Log::error(
					"(Math::add) undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 3, mem);
		}

		//---------------------------------------------------------------------
		
		bool sub(Array *a, Array *b, Array *result) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Internal::Array *i_b = (Internal::Array *)(b);
			Internal::Array *i_result = (Internal::Array *)(result);
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			if(	i_b->getType() != type ||
				i_result->getType() != type ||
				i_b->getSize() != size ||
				i_result->getSize() != size ||
				i_b->getContext() != context ||
				i_result->getContext() != context) {
				Internal::Log::error(
					"(Math::sub) invalid array type/size/context.");
				return false;
			}
			cl_mem mem[3] = {
				i_a->getMemory(),
				i_b->getMemory(),
				i_result->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Char:
				program = Internal::Program::EPH_AA_Sub_Char;
				break;
			case Type::EPH_UChar:
				program = Internal::Program::EPH_AA_Sub_UChar;
				break;
			case Type::EPH_Short:
				program = Internal::Program::EPH_AA_Sub_Short;
				break;
			case Type::EPH_UShort:
				program = Internal::Program::EPH_AA_Sub_UShort;
				break;
			case Type::EPH_Int:
				program = Internal::Program::EPH_AA_Sub_Int;
				break;
			case Type::EPH_UInt:
				program = Internal::Program::EPH_AA_Sub_UInt;
				break;
			case Type::EPH_Long:
				program = Internal::Program::EPH_AA_Sub_Long;
				break;
			case Type::EPH_ULong:
				program = Internal::Program::EPH_AA_Sub_ULong;
				break;
			case Type::EPH_Float:
				program = Internal::Program::EPH_AA_Sub_Float;
				break;
			case Type::EPH_Double:
				program = Internal::Program::EPH_AA_Sub_Double;
				break;
			default:
				Internal::Log::error(
					"(Math::sub) undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 3, mem);
		}

		//---------------------------------------------------------------------
		
		bool mul(Array *a, Array *b, Array *result) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Internal::Array *i_b = (Internal::Array *)(b);
			Internal::Array *i_result = (Internal::Array *)(result);
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			if(	i_b->getType() != type ||
				i_result->getType() != type ||
				i_b->getSize() != size ||
				i_result->getSize() != size ||
				i_b->getContext() != context ||
				i_result->getContext() != context) {
				Internal::Log::error(
					"(Math::mul) invalid array type/size/context.");
				return false;
			}
			cl_mem mem[3] = {
				i_a->getMemory(),
				i_b->getMemory(),
				i_result->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Char:
				program = Internal::Program::EPH_AA_Mul_Char;
				break;
			case Type::EPH_UChar:
				program = Internal::Program::EPH_AA_Mul_UChar;
				break;
			case Type::EPH_Short:
				program = Internal::Program::EPH_AA_Mul_Short;
				break;
			case Type::EPH_UShort:
				program = Internal::Program::EPH_AA_Mul_UShort;
				break;
			case Type::EPH_Int:
				program = Internal::Program::EPH_AA_Mul_Int;
				break;
			case Type::EPH_UInt:
				program = Internal::Program::EPH_AA_Mul_UInt;
				break;
			case Type::EPH_Long:
				program = Internal::Program::EPH_AA_Mul_Long;
				break;
			case Type::EPH_ULong:
				program = Internal::Program::EPH_AA_Mul_ULong;
				break;
			case Type::EPH_Float:
				program = Internal::Program::EPH_AA_Mul_Float;
				break;
			case Type::EPH_Double:
				program = Internal::Program::EPH_AA_Mul_Double;
				break;
			default:
				Internal::Log::error(
					"(Math::mul) undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 3, mem);
		}

		//---------------------------------------------------------------------
		
		bool div(Array *a, Array *b, Array *result) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Internal::Array *i_b = (Internal::Array *)(b);
			Internal::Array *i_result = (Internal::Array *)(result);
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			if(	i_b->getType() != type ||
				i_result->getType() != type ||
				i_b->getSize() != size ||
				i_result->getSize() != size ||
				i_b->getContext() != context ||
				i_result->getContext() != context) {
				Internal::Log::error(
					"(Math::div) invalid array type/size/context.");
				return false;
			}
			cl_mem mem[3] = {
				i_a->getMemory(),
				i_b->getMemory(),
				i_result->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Char:
				program = Internal::Program::EPH_AA_Div_Char;
				break;
			case Type::EPH_UChar:
				program = Internal::Program::EPH_AA_Div_UChar;
				break;
			case Type::EPH_Short:
				program = Internal::Program::EPH_AA_Div_Short;
				break;
			case Type::EPH_UShort:
				program = Internal::Program::EPH_AA_Div_UShort;
				break;
			case Type::EPH_Int:
				program = Internal::Program::EPH_AA_Div_Int;
				break;
			case Type::EPH_UInt:
				program = Internal::Program::EPH_AA_Div_UInt;
				break;
			case Type::EPH_Long:
				program = Internal::Program::EPH_AA_Div_Long;
				break;
			case Type::EPH_ULong:
				program = Internal::Program::EPH_AA_Div_ULong;
				break;
			case Type::EPH_Float:
				program = Internal::Program::EPH_AA_Div_Float;
				break;
			case Type::EPH_Double:
				program = Internal::Program::EPH_AA_Div_Double;
				break;
			default:
				Internal::Log::error(
					"(Math::div) undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 3, mem);
		}
		
		//---------------------------------------------------------------------
		
	}

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------