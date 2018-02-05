#pragma once

namespace tl {

	// Idea taken from WildMagic5
	// Avoid warnings about unused variables.  This is designed for variables
	// that are exposed in debug configurations but are hidden in release
	// configurations.
#define TLOC_UNUSED(variable) (void)variable
#define TLOC_UNUSED_2(variable1, variable2) TLOC_UNUSED(variable1); TLOC_UNUSED(variable2)
#define TLOC_UNUSED_3(variable1, variable2, variable3) TLOC_UNUSED_2(variable1, variable2); TLOC_UNUSED(variable3)
#define TLOC_UNUSED_4(variable1, variable2, variable3, variable4) TLOC_UNUSED_3(variable1, variable2, variable3); TLOC_UNUSED(variable4)
#define TLOC_UNUSED_5(variable1, variable2, variable3, variable4, variable5) TLOC_UNUSED_4(variable1, variable2, variable3, variable4); TLOC_UNUSED(variable5)
#define TLOC_UNUSED_6(variable1, variable2, variable3, variable4, variable5, variable6) TLOC_UNUSED_5(variable1, variable2, variable3, variable4, variable5); TLOC_UNUSED(variable6)
#define TLOC_UNUSED_7(variable1, variable2, variable3, variable4, variable5, variable6, variable7) TLOC_UNUSED_6(variable1, variable2, variable3, variable4, variable5, variable6); TLOC_UNUSED(variable7)

	// If a source file is empty (usually because of #ifdef) then the linker will
	// generate the LNK4221 warning complaining that no symbols were found and hence
	// the archive member (in the library) will be inaccessible. In most cases, we
	// are intentionally leaving the source file empty. In those cases, the following
	// define can be used (taken from: http://stackoverflow.com/questions/1822887/what-is-the-best-way-to-eliminate-ms-visual-c-linker-warning-warning-lnk4221/1823024#1823024

#ifdef _MSC_VER
# define TLOC_INTENTIONALLY_EMPTY_SOURCE_FILE() \
	namespace { char NoEmptyFileDummy##__LINE__; }
# define TLOC_NOT_EMPTY_SOURCE_FILE() \
	namespace { char NoEmptyFileDummy##__LINE__; }
#else
# define TLOC_INTENTIONALLY_EMPTY_SOURCE_FILE()
# define TLOC_NOT_EMPTY_SOURCE_FILE()
#endif
};
