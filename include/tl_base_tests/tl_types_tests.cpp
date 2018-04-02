#include <catch.hpp>

#include <tl_base/tl_types.h>

namespace tl { namespace tests {

  TEST_CASE("types", "")
  {
    static_assert(sizeof(u8)  == 1, "Size of u8 is not 1 byte");
    static_assert(sizeof(u16) == 2, "Size of u16 is not 2 bytes");
    static_assert(sizeof(u32) == 4, "Size of u32 is not 4 bytes");
    static_assert(sizeof(u64) == 8, "Size of u64 is not 8 bytes");

    static_assert(sizeof(s8)  == 1, "Size of s8 is not 1 byte");
    static_assert(sizeof(s16) == 2, "Size of s16 is not 2 bytes");
    static_assert(sizeof(s32) == 4, "Size of s32 is not 4 bytes");
    static_assert(sizeof(s64) == 8, "Size of s64 is not 8 bytes");
  }

};};
