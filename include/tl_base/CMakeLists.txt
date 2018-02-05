# -----------------------------------------------------------------------------

include("${tl_base_ci_INCLUDE_DIRECTORIES}/tl_base_ci/tl_add_library.cmake")

# -----------------------------------------------------------------------------

set(LIB_NAME "tl_base")

# -----------------------------------------------------------------------------

set(${LIB_NAME}_PUBLIC_HEADER_FILES
  "tl_common.h"
  "tl_exception.h"
  "tl_platform.h"
  "tl_pointer.h"
  "tl_types.h"
  "tl_unused.h"
  )

set(${LIB_NAME}_SOURCE_FILES
  "tl_common.cpp"
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
  )

# -----------------------------------------------------------------------------
