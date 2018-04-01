#include <catch.hpp>
#include <vector>

#include <tl_base/tl_pointer.h>

class test_class
{
  public:
    test_class() = default;
};

TLOC_TYPEDEF_UNIQUE_PTR(test_class);
TLOC_TYPEDEF_SHARED_PTR(test_class);

TEST_CASE("Pointer typedefs", "")
{
  test_class_uptr my_unique_ptr = std::make_unique<test_class>();
  test_class_sptr my_shared_ptr = std::make_unique<test_class>();
}
