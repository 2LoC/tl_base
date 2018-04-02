#include <catch.hpp>

#include <tl_base/tl_getter_setter.h>

namespace tl { namespace tests {

  class test_class
  {
    public:
      test_class() = default;

      TLOC_DECL_GETTER(int, GetA) { return a; }
      TLOC_DECL_GETTER_NON_CONST(int, GetB) { return b; }
      TLOC_DECL_GETTER_REF(int, GetC) { return c; }
      TLOC_DECL_GETTER_CONST_REF(int, GetD) { return d; }

      TLOC_DECL_AND_DEF_GETTER(int, GetE, e);
      TLOC_DECL_AND_DEF_GETTER_NON_CONST(int, GetF, f);

      TLOC_DECL_AND_DEF_GETTER_REF(int, GetG, g);
      TLOC_DECL_AND_DEF_GETTER_CONST_REF(int, GetH, h);

    private:
      int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7;
  };

  TEST_CASE("Getters", "")
  {
    test_class t {};
    const test_class tc {};

    SECTION("Getters")
    {
      CHECK(tc.GetA() == 0);
      CHECK(t.GetB() == 1);
      CHECK(t.GetC() == 2);
      {
        t.GetC() = 0;
        CHECK(t.GetC() == 0);
      }
      CHECK(tc.GetD() == 3);
      CHECK(tc.GetE() == 4);
      CHECK(t.GetF() == 5);
      CHECK(t.GetG() == 6);
      {
        t.GetG() = 1;
        CHECK(t.GetG() == 1);
      }
      CHECK(tc.GetH() == 7);
    }
  }

};};
