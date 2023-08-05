//
//  gravity_config.h
//  gravity
//
//  Created by Scott Ramsay on 18/6/20.
//  Copyright (c) 2014 CreoLabs. All rights reserved.
//

#ifndef __GRAVITY_CONFIG__
#define __GRAVITY_CONFIG__

#ifdef _MSC_VER

#pragma comment(lib, "shlwapi")
#include <basetsd.h>



#define GRAVITY_VERSION                     "0.8.2"     // git tag 0.8.2
#define GRAVITY_VERSION_NUMBER              0x000802    // git push --tags
#define GRAVITY_BUILD_DATE                  __DATE__

#define GRAVITY_ENABLE_DOUBLE               1           // if 1 enable gravity_float_t to be a double (instead of a float)
#define GRAVITY_ENABLE_INT64                1           // if 1 enable gravity_int_t to be a 64bit int (instead of a 32bit int)
#define GRAVITY_NULL_SILENT                 1           // if 1 then messages sent to null does not produce any runtime error
#define GRAVITY_MAP_DOTSUGAR                1           // if 1 then map objects can be accessed with both map[key] and map.key
#define GRAVITY_COMPUTED_GOTO               1           // if 1 enable faster computed goto (instead of switch) for compilers that support it

#if defined(_MSC_VER) && !defined(__clang__)
#undef GRAVITY_COMPUTED_GOTO
#define GRAVITY_COMPUTED_GOTO               0           // MSVC does not support computed goto (supported if using clang on Windows)
#endif


#if (!defined(HAVE_BZERO) || !defined(bzero))
#define bzero(b, len) memset((b), 0, (len))
#endif

#if (!defined(HAVE_SNPRINTF) || !defined(snprintf))
#define snprintf    _snprintf
#endif

typedef SSIZE_T     ssize_t;
typedef int         mode_t;

#define open        _open
#define close       _close
#define read        _read
#define write       _write
#define __func__    __FUNCTION__
#define PATH_SEPARATOR  '\\'
#else
#include <unistd.h>
#define PATH_SEPARATOR  '/'
#endif

// check if the compiler supports designated initializers when using c++
#ifndef GRAVITY_USE_HIDDEN_INITIALIZERS
    #if __cplusplus && (__cplusplus < 202002L)
        // C++ di requires C++20
        #define GRAVITY_USE_HIDDEN_INITIALIZERS 1
    #endif // __cplusplus
#endif // GRAVITY_USE_HIDDEN_INITIALIZERS

#endif // __GRAVITY_CONFIG__
