//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/EphedrineMath.h
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

#ifndef __EPHEDRINE_MATH_H__
#define __EPHEDRINE_MATH_H__

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
	// Array class forward declaration.
	//
	//-------------------------------------------------------------------------
	
	class Array;
	
	//-------------------------------------------------------------------------
	//
	// Basic math operations.
	//
	//-------------------------------------------------------------------------
	
	namespace Math {
		
		//---------------------------------------------------------------------
		//
		// Increment operator.
		// Executed for each array element.
		//
		// a 		Argument.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool inc(Array *a);
		
		//---------------------------------------------------------------------
		//
		// Decrement operator.
		// Executed for each array element.
		//
		// a 		Argument.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool dec(Array *a);
		
		//---------------------------------------------------------------------
		//
		// Addition operator.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		First argument.
		// b 		Second argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool add(Array *a, Array *b, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Substraction operator.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		First argument.
		// b 		Second argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool sub(Array *a, Array *b, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Multiplication operator.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		First argument.
		// b 		Second argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool mul(Array *a, Array *b, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Division operator.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		First argument.
		// b 		Second argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool div(Array *a, Array *b, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Cosine.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool cos(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Sine.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool sin(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Tangent.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool tan(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Arc cosine.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool acos(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Arc sine.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool asin(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Arc tangent.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool atan(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Cube-root.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool cbrt(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Round to integral value.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool ceil(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Error function encountered in integrating the normal distribution.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool erf(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Complementary error function.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool erfc(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Exponential base 'e'.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool exp(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Exponential base 2.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool exp2(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Exponential base 10.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool exp10(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Absolute value of a floating-point number.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool fabs(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Round to integral value.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool floor(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Natural logarithm.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool log(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Base 2 logarithm.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool log2(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Base 10 logarithm.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool log10(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Round to integral value.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool trunc(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		//
		// Round to integral value.
		// Executed for each array element.
		// Arrays must have the same context, type and size.
		//
		// a 		Argument.
		// result 	Array to store operation result.
		//
		// Returns true on evaluated succesfully, false - otherwise.
		//
		//---------------------------------------------------------------------
		
		EPHEDRINE_API bool round(Array *a, Array *result);
		
		//---------------------------------------------------------------------
		
	}

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_MATH_H__

//-----------------------------------------------------------------------------