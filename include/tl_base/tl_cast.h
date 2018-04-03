#pragma once

#include "tl_types.h"

namespace tl {

  //------------------------------------------------------------------------
  // Safe 32-bit to 64-bit type conversions with sanity checks

  ///-------------------------------------------------------------------------
  /// @brief Converts an a_value to a 32 bit number.
  ///
  /// @param  a_value The value.
  ///
  /// @note A linking error means the type conversion you are looking for is
  /// not supported.
  ///-------------------------------------------------------------------------
  template <typename t_return_type, typename t_to_cast>
  t_return_type cast_32(t_to_cast a_value);

  ///-------------------------------------------------------------------------
  /// @brief
  /// Cast numbers from signed to unsigned and vice versa. This function
  /// will fire an assertion if the cast results in a loss of data.
  ///
  /// @param  a_value The casted value
  ///-------------------------------------------------------------------------
  template <typename t_return_type, typename t_to_cast>
  t_return_type cast(t_to_cast a_value);

};
