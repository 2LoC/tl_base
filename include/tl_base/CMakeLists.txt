# -----------------------------------------------------------------------------

set(LIB_NAME "tl_base")

# -----------------------------------------------------------------------------

set(${LIB_NAME}_PUBLIC_HEADER_FILES
  "tl_common.h"
  "tl_container.h"
  "tl_exception.h"
  "tl_getter_setter.h"
  "tl_platform.h"
  "tl_pointer.h"
  "tl_types.h"
  "tl_unused.h"
  )

set(${LIB_NAME}_SOURCE_FILES
  "tl_cast.cpp"
  "tl_common.cpp"
  "tl_container.cpp"
  "tl_exception.cpp"
  "tl_pointer.cpp"
  )

# -----------------------------------------------------------------------------

tl_add_library(
  LIB_NAME
    ${LIB_NAME}
  PUBLIC_HEADER_FILES
    ${${LIB_NAME}_PUBLIC_HEADER_FILES}
  SOURCE_FILES
    ${${LIB_NAME}_SOURCE_FILES}
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  )

# -----------------------------------------------------------------------------
