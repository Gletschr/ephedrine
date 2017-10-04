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
		// Array/Array addition operator.
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
		// Array/Array substraction operator.
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
		// Array/Array multiplication operator.
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
		// Array/Array division operator.
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
		
	}

	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_MATH_H__

//-----------------------------------------------------------------------------