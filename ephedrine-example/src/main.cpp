//-----------------------------------------------------------------------------
//
// Ephedrine API example project
//
// File: src/main.cpp
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

#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------

#include "Ephedrine.h"

//-----------------------------------------------------------------------------

int main(int argc, const char **argv) {

	//
	using namespace Ephedrine;

	// create context
	Context *context = Context::create(Device::EPH_GPU_1);

	//
	if(!context) return -1;

	//
	printf("[Ephedrine]: context created succesfully.\n");

	// array size
	constexpr size_t size = 128;

	// create arrays
	Array *a = context->createArray(Type::EPH_Float, size);
	Array *b = context->createArray(Type::EPH_Float, size);
	Array *r = context->createArray(Type::EPH_Float, size);

	//
	float in[size];
	
	//
	for(size_t i = 0; i < size; ++ i) in[i] = 2.f;

	// set default values
	if(	!a->setRawData((const uint8_t *)in, 0, sizeof(in)) ||
		!b->setRawData((const uint8_t *)in, 0, sizeof(in))) return -1;

	// exec array add operator
	if (!Math::mul(a, b, r)) return -1;

	//
	float out[size];

	//
	if(!r->getRawData((uint8_t *)out, 0, sizeof(out))) return -1;

	//
	for(size_t i = 0; i < size; ++ i)
		printf("r[%zi] = %f\n", i, out[i]);

	// delete arrays 
	delete a;
	delete b;
	delete r;

	// delete context
	delete context;

	//
	system("pause");

	return 0;
}

//-----------------------------------------------------------------------------