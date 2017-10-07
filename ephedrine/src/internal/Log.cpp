//-----------------------------------------------------------------------------
//
// Ephedrine API
//
// File: src/internal/Log.cpp
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
#include <stdarg.h>

//-----------------------------------------------------------------------------

#include "internal/Log.h"

//-----------------------------------------------------------------------------

namespace Internal {
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_LOG_PRINTF(color, format) \
	static char buffer[512]; \
	va_list va; \
	va_start(va, format); \
	vsnprintf(buffer, sizeof(buffer), format, va); \
	va_end(va); \
	printf("%s%s\n", "[Ephedrine]: ", buffer);
	
	//-------------------------------------------------------------------------
	
	#define EPHEDRINE_LOG_COLOR_RED ""
	#define EPHEDRINE_LOG_COLOR_GREEN ""
	#define EPHEDRINE_LOG_COLOR_YELLOW ""
	#define EPHEDRINE_LOG_COLOR_WHITE ""
	
	//-------------------------------------------------------------------------
	
	void Log::message(const char *format, ...) {
		EPHEDRINE_LOG_PRINTF(EPHEDRINE_LOG_COLOR_WHITE, format);
	}
	
	//-------------------------------------------------------------------------
	
	void Log::success(const char *format, ...) {
		EPHEDRINE_LOG_PRINTF(EPHEDRINE_LOG_COLOR_GREEN, format);
	}
	
	//-------------------------------------------------------------------------
	
	void Log::error(const char *format, ...) {
		EPHEDRINE_LOG_PRINTF(EPHEDRINE_LOG_COLOR_RED, format);
	}
	
	//-------------------------------------------------------------------------
	
	void Log::warning(const char *format, ...) {
		EPHEDRINE_LOG_PRINTF(EPHEDRINE_LOG_COLOR_YELLOW, format);
	}
	
	//-------------------------------------------------------------------------
	
}

//-----------------------------------------------------------------------------