#include <catch.hpp>

#include <tl_base/tl_cast.h>

namespace tl { namespace tests {

  TEST_CASE("number cast_32()", "")
  {
    CHECK( (cast_32<s32, s64>(60) == 60) );
    CHECK( (cast_32<s32, s32>(60) == 60) );

    CHECK( (cast_32<f32, f64>(60.0) == Approx(60.0f)) );
    CHECK( (cast_32<f32, f32>(60.0f) == Approx(60.0f)) );
  }

  TEST_CASE("number cast()", "")
  {
    CHECK( (cast<s8, s32>(100) == 100) );
    CHECK( (cast<s8, s32>(-100) == -100) );

    CHECK( (cast<s8, u32>(100) == 100) );

    CHECK( (cast<u8, s32>(100) == 100) );
    CHECK( (cast<u8, s32>(200) == 200) );

    CHECK( (cast<u8, u32>(100) == 100) );
    CHECK( (cast<u8, u32>(200) == 200) );

    CHECK( (cast<s32, s8>(100) == 100) );
    CHECK( (cast<s32, s8>(-100) == -100) );
    CHECK( (cast<s32, u8>(100) == 100) );

    CHECK( (cast<u32, s8>(100) == 100) );
    CHECK( (cast<u32, u8>(100) == 100) );

    CHECK( (cast<u32, s32>(60) == 60) );
    CHECK( (cast<s32, u32>(60) == 60) );

    CHECK( (cast<u32, u32>(60) == 60) );
    CHECK( (cast<s32, s32>(60) == 60) );

    CHECK( (cast<f32, f32>(60.0) == Approx(60.0f)) );
    CHECK( (cast<f32, f64>(60.0) == Approx(60.0f)) );

    CHECK( (cast<f64, f32>(60.0f) == Approx(60.0)) );
    CHECK( (cast<f64, f32>(60.0f) == Approx(60.0)) );
  }

};};
