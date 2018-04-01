#pragma once

namespace tl {

// ///////////////////////////////////////////////////////////////////////
// Trigger compiler warning/error
// taken from: https://stackoverflow.com/a/2706693/368599
#define EMIT_COMPILER_WARNING_STRINGIFY0(x) #x
#define EMIT_COMPILER_WARNING_STRINGIFY1(x) EMIT_COMPILER_WARNING_STRINGIFY0(x)
#define EMIT_COMPILER_MESSAGE_PREFACE(type) \
    __FILE__ "(" EMIT_COMPILER_WARNING_STRINGIFY1(__LINE__) "): " type ": "

#define EMIT_COMPILER_MESSAGE EMIT_COMPILER_MESSAGE_PREFACE("message")
#define EMIT_COMPILER_WARNING EMIT_COMPILER_MESSAGE_PREFACE("warning")
#define EMIT_COMPILER_ERROR   EMIT_COMPILER_MESSAGE_PREFACE("error")

#ifndef TLOC_PLATFORM_DEFINES_H
#define TLOC_PLATFORM_DEFINES_H

#ifdef __APPLE__
# include "TargetConditionals.h"
#endif

// ///////////////////////////////////////////////////////////////////////
// playform macros

#if defined(_WIN64)
# define TLOC_WIN64
#elif defined(WIN32) || defined(_WIN32)
# define TLOC_WIN32
#elif defined(TARGET_OS_IPHONE)
# define TLOC_OS_IPHONE
#elif defined(TARGET_OS_MAC)
# define TLOC_OS_MAC
#elif defined(__linux__)
# define TLOC_OS_LINUX
#else
# pragma message(EMIT_COMPILER_WARNING "Unsupported Platform")
#endif

// ///////////////////////////////////////////////////////////////////////
// compiler macros

#if defined(_MSC_VER)
# define TLOC_COMPILER_VISUAL_CPP _MSC_VER
# if TLOC_COMPILER_VISUAL_CPP < 1600
#   define TLOC_COMPILER_VISUAL_CPP_UNSUPPORTED
# endif
# if TLOC_COMPILER_VISUAL_CPP >= 1900
#   define TLOC_COMPILER_VISUAL_CPP_2015
# elif TLOC_COMPILER_VISUAL_CPP >= 1800
#   define TLOC_COMPILER_VISUAL_CPP_2013
# elif TLOC_COMPILER_VISUAL_CPP >= 1700
#   define TLOC_COMPILER_VISUAL_CPP_2012
# elif TLOC_COMPILER_VISUAL_CPP >= 1600
#   define TLOC_COMPILER_VISUAL_CPP_2010
# endif
#elif defined (__GNUC__)
# define TLOC_COMPILER_GCC
#elif defined (__clang__)
# define TLOC_COMPILER_CLANG
#endif

// Convenience Macro

#if defined (TLOC_WIN32) || defined (TLOC_WIN64)
# define TLOC_OS_WIN
#endif

#if defined (TLOC_COMPILER_VISUAL_CPP)
# define TLOC_FUNCTION_NAME __FUNCSIG__
#elif defined (TLOC_COMPILER_GCC)
# define TLOC_FUNCTION_NAME __PRETTY_FUNCTION__
#elif defined (TLOC_COMPILER_CLANG)
# define TLOC_FUNCTION_NAME __PRETTY_FUNCTION__
#endif

#endif

};
