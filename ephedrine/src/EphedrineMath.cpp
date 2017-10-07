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
		
		bool validate(Internal::Array *a, Internal::Array *b) {
			return 	a->getType() == b->getType() &&
					a->getSize() == b->getSize() &&
					a->getContext() == b->getContext();
		}
		
		//---------------------------------------------------------------------
		
		bool validate(
			Internal::Array *a, Internal::Array *b, Internal::Array *c) {
			
			return 	validate(a, b) && validate(b, c);
		}
		
		//---------------------------------------------------------------------
		
		bool aa_uop_ext(unsigned offset, Array *a) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			cl_mem mem[1] = {
				i_a->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Char:
				program = Internal::Program(offset);
				break;
			case Type::EPH_UChar:
				program = Internal::Program(offset + 1);
				break;
			case Type::EPH_Short:
				program = Internal::Program(offset + 2);
				break;
			case Type::EPH_UShort:
				program = Internal::Program(offset + 3);
				break;
			case Type::EPH_Int:
				program = Internal::Program(offset + 4);
				break;
			case Type::EPH_UInt:
				program = Internal::Program(offset + 5);
				break;
			case Type::EPH_Long:
				program = Internal::Program(offset + 6);
				break;
			case Type::EPH_ULong:
				program = Internal::Program(offset + 7);
				break;
			case Type::EPH_Float:
				program = Internal::Program(offset + 8);
				break;
			case Type::EPH_Double:
				program = Internal::Program(offset + 9);
				break;
			default:
				Internal::Log::error(
					"undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 1, mem);
		}
		
		//---------------------------------------------------------------------
		
		bool aa_bop_ext(unsigned offset, Array *a, Array *b, Array *result) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Internal::Array *i_b = (Internal::Array *)(b);
			Internal::Array *i_result = (Internal::Array *)(result);
			if(!validate(i_a, i_b, i_result)) {
				Internal::Log::error(
					"invalid array type/size/context.");
				return false;
			}
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			cl_mem mem[3] = {
				i_a->getMemory(),
				i_b->getMemory(),
				i_result->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Char:
				program = Internal::Program(offset);
				break;
			case Type::EPH_UChar:
				program = Internal::Program(offset + 1);
				break;
			case Type::EPH_Short:
				program = Internal::Program(offset + 2);
				break;
			case Type::EPH_UShort:
				program = Internal::Program(offset + 3);
				break;
			case Type::EPH_Int:
				program = Internal::Program(offset + 4);
				break;
			case Type::EPH_UInt:
				program = Internal::Program(offset + 5);
				break;
			case Type::EPH_Long:
				program = Internal::Program(offset + 6);
				break;
			case Type::EPH_ULong:
				program = Internal::Program(offset + 7);
				break;
			case Type::EPH_Float:
				program = Internal::Program(offset + 8);
				break;
			case Type::EPH_Double:
				program = Internal::Program(offset + 9);
				break;
			default:
				Internal::Log::error(
					"undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 3, mem);
		}
		
		//---------------------------------------------------------------------
		
		bool a_fn1_ext(unsigned offset, Array *a, Array *result) {
			Internal::Array *i_a = (Internal::Array *)(a);
			Internal::Array *i_result = (Internal::Array *)(result);
			Type type = i_a->getType();
			size_t size = i_a->getSize();
			Internal::Context *context = i_a->getContext();
			if(	i_result->getType() != type ||
				i_result->getSize() != size ||
				i_result->getContext() != context) {
				Internal::Log::error(
					"invalid array type/size/context.");
				return false;
			}
			cl_mem mem[2] = {
				i_a->getMemory(),
				i_result->getMemory(),
			};
			Internal::Program program;
			switch(type) {
			case Type::EPH_Float:
				program = Internal::Program(offset);
				break;
			case Type::EPH_Double:
				program = Internal::Program(offset + 1);
				break;
			default:
				Internal::Log::error(
					"undefined array type %i.", type);
				return false;
			}
			return context->runProgram(program, size, 2, mem);
		}
		
		//---------------------------------------------------------------------
		
		bool inc(Array *a) {
			return aa_uop_ext(
				Internal::Program::EPH_A_Inc_Char, a);
		}

		//---------------------------------------------------------------------
		
		bool dec(Array *a) {
			return aa_uop_ext(
				Internal::Program::EPH_A_Dec_Char, a);
		}
		
		//---------------------------------------------------------------------
		
		bool add(Array *a, Array *b, Array *result) {
			return aa_bop_ext(
				Internal::Program::EPH_AA_Add_Char, a, b, result);
		}

		//---------------------------------------------------------------------
		
		bool sub(Array *a, Array *b, Array *result) {
			return aa_bop_ext(
				Internal::Program::EPH_AA_Sub_Char, a, b, result);
		}

		//---------------------------------------------------------------------
		
		bool mul(Array *a, Array *b, Array *result) {
			return aa_bop_ext(
				Internal::Program::EPH_AA_Mul_Char, a, b, result);
		}

		//---------------------------------------------------------------------
		
		bool div(Array *a, Array *b, Array *result) {
			return aa_bop_ext(
				Internal::Program::EPH_AA_Div_Char, a, b, result);
		}
		
		//---------------------------------------------------------------------
		
		bool cos(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Cos_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool sin(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Sin_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool tan(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Tan_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool acos(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Acos_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool asin(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Asin_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool atan(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Atan_Float, a, result);
		}	
		
		//---------------------------------------------------------------------
		
		bool cbrt(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Cbrt_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool ceil(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Ceil_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool erf(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Erf_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool erfc(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Erfc_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool exp(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Exp_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool exp2(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Exp2_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool exp10(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Exp10_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool fabs(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Fabs_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool floor(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Floor_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool log(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Log_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool log2(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Log2_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool log10(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Log10_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool trunc(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Trunc_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
		bool round(Array *a, Array *result) {
			return a_fn1_ext(
				Internal::Program::EPH_A_Round_Float, a, result);
		}
		
		//---------------------------------------------------------------------
		
	}

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------