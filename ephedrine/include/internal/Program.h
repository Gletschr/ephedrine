//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/internal/Program.h
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

#ifndef __EPHEDRINE_PROGRAM_INTERNAL_H__
#define __EPHEDRINE_PROGRAM_INTERNAL_H__

//-----------------------------------------------------------------------------
//
// Ephedrine API internal namespace.
//
//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	//
	// Program type enumerator.
	//
	//-------------------------------------------------------------------------
	
	enum Program {
		
		EPH_A_Inc_Char = 0x00,
		EPH_A_Inc_UChar,
		EPH_A_Inc_Short,
		EPH_A_Inc_UShort,
		EPH_A_Inc_Int,
		EPH_A_Inc_UInt,
		EPH_A_Inc_Long,
		EPH_A_Inc_ULong,
		EPH_A_Inc_Float,
		EPH_A_Inc_Double,
		
		EPH_A_Dec_Char,
		EPH_A_Dec_UChar,
		EPH_A_Dec_Short,
		EPH_A_Dec_UShort,
		EPH_A_Dec_Int,
		EPH_A_Dec_UInt,
		EPH_A_Dec_Long,
		EPH_A_Dec_ULong,
		EPH_A_Dec_Float,
		EPH_A_Dec_Double,
		
		EPH_AA_Add_Char,
		EPH_AA_Add_UChar,
		EPH_AA_Add_Short,
		EPH_AA_Add_UShort,
		EPH_AA_Add_Int,
		EPH_AA_Add_UInt,
		EPH_AA_Add_Long,
		EPH_AA_Add_ULong,
		EPH_AA_Add_Float,
		EPH_AA_Add_Double,

		EPH_AA_Sub_Char,
		EPH_AA_Sub_UChar,
		EPH_AA_Sub_Short,
		EPH_AA_Sub_UShort,
		EPH_AA_Sub_Int,
		EPH_AA_Sub_UInt,
		EPH_AA_Sub_Long,
		EPH_AA_Sub_ULong,
		EPH_AA_Sub_Float,
		EPH_AA_Sub_Double,
		
		EPH_AA_Mul_Char,
		EPH_AA_Mul_UChar,
		EPH_AA_Mul_Short,
		EPH_AA_Mul_UShort,
		EPH_AA_Mul_Int,
		EPH_AA_Mul_UInt,
		EPH_AA_Mul_Long,
		EPH_AA_Mul_ULong,
		EPH_AA_Mul_Float,
		EPH_AA_Mul_Double,
		
		EPH_AA_Div_Char,
		EPH_AA_Div_UChar,
		EPH_AA_Div_Short,
		EPH_AA_Div_UShort,
		EPH_AA_Div_Int,
		EPH_AA_Div_UInt,
		EPH_AA_Div_Long,
		EPH_AA_Div_ULong,
		EPH_AA_Div_Float,
		EPH_AA_Div_Double,
		
		EPH_A_Cos_Float,
		EPH_A_Cos_Double,
		
		EPH_A_Sin_Float,
		EPH_A_Sin_Double,
		
		EPH_A_Tan_Float,
		EPH_A_Tan_Double,
		
		EPH_A_Acos_Float,
		EPH_A_Acos_Double,
		
		EPH_A_Asin_Float,
		EPH_A_Asin_Double,
		
		EPH_A_Atan_Float,
		EPH_A_Atan_Double,
		
		EPH_A_Cbrt_Float,
		EPH_A_Cbrt_Double,
		
		EPH_A_Ceil_Float,
		EPH_A_Ceil_Double,
		
		EPH_A_Erf_Float,
		EPH_A_Erf_Double,
		
		EPH_A_Erfc_Float,
		EPH_A_Erfc_Double,
		
		EPH_A_Exp_Float,
		EPH_A_Exp_Double,
		
		EPH_A_Exp2_Float,
		EPH_A_Exp2_Double,
		
		EPH_A_Exp10_Float,
		EPH_A_Exp10_Double,
		
		EPH_A_Fabs_Float,
		EPH_A_Fabs_Double,
		
		EPH_A_Floor_Float,
		EPH_A_Floor_Double,
		
		EPH_A_Log_Float,
		EPH_A_Log_Double,
		
		EPH_A_Log2_Float,
		EPH_A_Log2_Double,
		
		EPH_A_Log10_Float,
		EPH_A_Log10_Double,
		
		EPH_A_Trunc_Float,
		EPH_A_Trunc_Double,
		
		EPH_A_Round_Float,
		EPH_A_Round_Double,
		
	};

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_PROGRAM_INTERNAL_H__

//-----------------------------------------------------------------------------