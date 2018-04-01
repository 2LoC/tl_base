#pragma once

#include <wctype.h>
#include <limits.h>
#include <stddef.h> // Needed for OSX built-in types
#include <stdint.h>

namespace tl {

//////////////////////////////////////////////////////////////////////////
// windows types

#if defined(WIN32) || defined(_WIN32) || defined (_WIN64)
#define TLOC_INT8_TYPE  __int8
#define TLOC_INT16_TYPE __int16
#define TLOC_INT32_TYPE __int32
#define TLOC_INT64_TYPE __int64

#define TLOC_U_INT8_TYPE unsigned TLOC_INT8_TYPE
#define TLOC_U_INT16_TYPE unsigned TLOC_INT16_TYPE
#define TLOC_U_INT32_TYPE unsigned TLOC_INT32_TYPE
#define TLOC_U_INT64_TYPE unsigned TLOC_INT64_TYPE

#define TLOC_SIZE_TYPE      size_t
#define TLOC_U_INT_PTR_TYPE uintptr_t
#define TLOC_PTR_DIFF_TYPE  ptrdiff_t
#endif

//////////////////////////////////////////////////////////////////////////
// OSX types

#if defined(TARGET_OS_MAC) || defined (__APPLE__) || defined (MACOSX) || defined (macintosh) || defined (Macintosh) || defined (__linux__)
#define TLOC_INT8_TYPE  __int8_t
#define TLOC_INT16_TYPE __int16_t
#define TLOC_INT32_TYPE __int32_t
#define TLOC_INT64_TYPE __int64_t

#define TLOC_U_INT8_TYPE  __uint8_t
#define TLOC_U_INT16_TYPE __uint16_t
#define TLOC_U_INT32_TYPE __uint32_t
#define TLOC_U_INT64_TYPE __uint64_t

#define TLOC_SIZE_TYPE      size_t
#define TLOC_U_INT_PTR_TYPE size_t
#define TLOC_PTR_DIFF_TYPE  ptrdiff_t
#endif

//////////////////////////////////////////////////////////////////////////
// linux types

	//-------------------------------------------------------------------------
  // basic types

  using u8     = unsigned char;
	using u16    = TLOC_U_INT16_TYPE;
	using u32    = TLOC_U_INT32_TYPE;
	using u64    = TLOC_U_INT64_TYPE;

  using char8  = char;
  using char32 = wchar_t;

	using s8     = TLOC_INT8_TYPE;
	using s16    = TLOC_INT16_TYPE;
	using s32    = TLOC_INT32_TYPE;
	using s64    = TLOC_INT64_TYPE;

  using f32    = float;
  using f64    = double;
  using f128   = long double;

	using ushort = unsigned short;
  using uchar8 = unsigned char;
  using uint   = unsigned int;

  using ulong  = unsigned long;

};

