#include "tl_cast.h"

#include "tl_types.h"
#include "tl_assert.h"

#include <type_traits>
#include <limits>

namespace tl {

  namespace
  {
#define CHECK_AND_CAST_TO_32(_type_)\
  TLOC_ASSERT(a_value < std::numeric_limits<_type_>::max(), \
    "Casting will result in loss of information!");\
      return (_type_)a_value

    template <typename t_return_type, typename t_to_cast>
    t_return_type do_cast_to_32(t_to_cast a_value)
    { return a_value; }

    template <>
    int do_cast_to_32<int, long>(long a_value)
    { CHECK_AND_CAST_TO_32(int); }

    template <>
    uint do_cast_to_32<uint, ulong>(ulong a_value)
    { CHECK_AND_CAST_TO_32(uint); }

    template <>
    f32 do_cast_to_32<f32, f64>(f64 a_value)
    { CHECK_AND_CAST_TO_32(f32); }

#undef CHECK_AND_CAST_TO_32
  };

  template <typename t_return_type, typename t_to_cast>
  t_return_type cast_32(t_to_cast a_value)
  {
    return do_cast_to_32<t_return_type, t_to_cast>(a_value);
  }

  namespace
  {
#define CHECK_AND_CAST_TO_SIGNED(_type_, _to_cast_)\
  TLOC_ASSERT(a_value <= (_to_cast_)std::numeric_limits<_type_>::max(), \
    "Casting will result in loss of information!");\
      return (_type_)a_value

#define CHECK_AND_CAST_SMALL_TO_SIGNED(_type_, _to_cast_)\
  TLOC_ASSERT( (_type_)a_value <= std::numeric_limits<_type_>::max(), \
    "Casting will result in loss of information!");\
      return (_type_)a_value

#define CHECK_AND_CAST_TO_UNSIGNED(_type_, _to_cast_)\
  TLOC_ASSERT(a_value >= 0 && (_type_)a_value <= \
              std::numeric_limits<_type_>::max(), \
                "Casting will result in loss of information!");\
    return (_type_)a_value

#define CHECK_AND_CAST_TO_UNSIGNED_SMALL(_type_, _to_cast_)\
  TLOC_ASSERT(a_value >= 0 && a_value <= \
              (_to_cast_)std::numeric_limits<_type_>::max(), \
                "Casting will result in loss of information!");\
    return (_type_)a_value

    template <typename t_return_type, typename t_to_cast>
    t_return_type do_cast_number(t_to_cast a_value)
    { return (t_return_type)a_value; }

    template <>
    s8 do_cast_number<s8, s32>(s32 a_value)
    { CHECK_AND_CAST_TO_SIGNED(s8, s32); }

    template <>
    s8 do_cast_number<s8, s64>(s64 a_value)
    { CHECK_AND_CAST_TO_SIGNED(s8, s64); }

    template <>
    s8 do_cast_number<s8, u32>(u32 a_value)
    { CHECK_AND_CAST_TO_SIGNED(s8, u32); }

    template <>
    s8 do_cast_number<s8, u64>(u64 a_value)
    { CHECK_AND_CAST_TO_SIGNED(s8, u64); }

    template <>
    u8 do_cast_number<u8, s32>(s32 a_value)
    { CHECK_AND_CAST_TO_UNSIGNED_SMALL(u8, s32); }

    template <>
    u8 do_cast_number<u8, s64>(s64 a_value)
    { CHECK_AND_CAST_TO_UNSIGNED_SMALL(u8, s64); }

    template <>
    u8 do_cast_number<u8, u32>(u32 a_value)
    { CHECK_AND_CAST_TO_UNSIGNED_SMALL(u8, u32); }

    template <>
    u8 do_cast_number<u8, u64>(u64 a_value)
    { CHECK_AND_CAST_TO_UNSIGNED_SMALL(u8, u64); }

    template <>
    s32 do_cast_number<s32, u32>(u32 a_value)
    { CHECK_AND_CAST_TO_SIGNED(s32, u32); }

    template <>
    u32 do_cast_number<u32, s32>(s32 a_value)
    { CHECK_AND_CAST_TO_UNSIGNED(u32, s32); }

#undef CHECK_AND_CAST_TO_SIGNED

  };

  template <typename T_return_type, typename T_to_cast>
  T_return_type cast(T_to_cast a_value)
  {
    return do_cast_number<T_return_type, T_to_cast>(a_value);
  }

  //------------------------------------------------------------------------
  // Explicit instantiations

  template s32 cast_32(s32);
  template s32 cast_32(s64);

  template u32 cast_32(u32);
  template u32 cast_32(u64);

  template f32 cast_32(f32);
  template f32 cast_32(f64);

#define INSTANTIATE_CAST(_type_)\
  template _type_  cast(s8);\
  template _type_  cast(u8);\
  template _type_  cast(s16);\
  template _type_  cast(u16);\
  template _type_  cast(s32);\
  template _type_  cast(u32);\
  template _type_  cast(s64);\
  template _type_  cast(u64);\
  template _type_  cast(f32);\
  template _type_  cast(f64);\

  INSTANTIATE_CAST(char32);
  INSTANTIATE_CAST(s8);
  INSTANTIATE_CAST(u8);
  INSTANTIATE_CAST(s16);
  INSTANTIATE_CAST(u16);
  INSTANTIATE_CAST(s32);
  INSTANTIATE_CAST(s64);
  INSTANTIATE_CAST(u32);
  INSTANTIATE_CAST(u64);
  INSTANTIATE_CAST(f32);
  INSTANTIATE_CAST(f64);

};
