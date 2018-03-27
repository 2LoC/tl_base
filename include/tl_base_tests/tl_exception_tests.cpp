#include <catch.hpp>

#include <tl_base/tl_exception.h>

TLOC_EXCEPTION_DEFINE(TestException);

TEST_CASE("Exception", "")
{
  auto throwTest = []() { TLOC_THROW_EXCEPTION(TestException, "Test Exception"); };
  REQUIRE_THROWS(throwTest());
}
