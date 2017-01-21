/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once

#if defined(__MINGW32__)
#define UNICODE
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// there's no <malloc.h> on OS X
#if !defined(__APPLE__) && !defined(__DragonFly__) &&			\
    !defined(__FreeBSD__) && !defined(__NetBSD__) &&			\
    !defined(__OpenBSD__)
#include <malloc.h>
#endif

#include <stdio.h>

#ifdef __MINGW32__
#include <stdlib.h>
#endif

#if !defined(__unix__) && !defined(__APPLE__)
#include <tchar.h>
#include <io.h>
#include <windows.h>

#ifndef __MINGW32__
#include <crtdbg.h>
#else
#include <stdexcept>
#endif

#else // !defined(__unix__) && !defined(__APPLE__)

#ifdef _XOPEN_SOURCE
#if (_XOPEN_SOURCE < 600)
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600  // for posix_memalign()
#endif // _XOPEN_SOURCE < 600
#else
#define _XOPEN_SOURCE 600  // for posix_memalign()
#endif //_XOPEN_SOURCE
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#endif // __unix__
#include <math.h>
#ifndef NO_PTHREAD
#if _MSC_VER >= 1900
// Workaround timespec redefinition: http://tinyurl.com/zcs2ocd
#define HAVE_STRUCT_TIMESPEC 1
#endif
#else
#include <pthread.h>
#endif

#ifdef FAR  // libjpeg also defines FAR
#ifdef WIN32_LEAN_AND_MEAN
#undef FAR
#endif
#endif

#ifdef _MSC_VER
#define __attribute__(p)
#endif

// STL
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <array>
#include <algorithm>
#include <numeric>

#include <float.h>

//My own
#include "tiff/TiffTag.h"
#include "common/Common.h"
#include "common/Point.h"
