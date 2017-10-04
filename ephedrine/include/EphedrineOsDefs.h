//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: include/EphedrineOsDefs.h
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

#ifndef __EPHEDRINE_OS_DEFS_H__
#define __EPHEDRINE_OS_DEFS_H__

//-----------------------------------------------------------------------------

#if defined(EPHEDRINE_DLL)
#	define EPHEDRINE_API __declspec(dllexport)
#else
#	define EPHEDRINE_API __declspec(dllimport)
#endif

//-----------------------------------------------------------------------------

#include <inttypes.h>

//-----------------------------------------------------------------------------

#define EPHEDRINE_INLINE inline

//-----------------------------------------------------------------------------

#define EPHEDRINE_UNUSED(x) (void)(x)

//-----------------------------------------------------------------------------

#include <assert.h>

//-----------------------------------------------------------------------------

#define EPHEDRINE_ASSERT(e, ...) assert(e)

//-----------------------------------------------------------------------------

#endif // __EPHEDRINE_OS_DEFS_H__

//-----------------------------------------------------------------------------