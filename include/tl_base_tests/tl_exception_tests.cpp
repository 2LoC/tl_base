#include <catch.hpp>
#include <vector>

#include <tl_base/tl_exception.h>

namespace tl { namespace tests {

  TLOC_EXCEPTION_DEFINE(test_exception);

  TEST_CASE("Exception", "")
  {
    auto throw_test = []() { TLOC_THROW_EXCEPTION(test_exception, "Test Exception"); };
    REQUIRE_THROWS(throw_test());
  }

};};
