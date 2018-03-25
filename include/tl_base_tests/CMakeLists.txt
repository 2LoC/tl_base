# -----------------------------------------------------------------------------

TLOC_INCLUDE("/tl_base_ci/tl_add_executable.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})

# -----------------------------------------------------------------------------

set(EXE_NAME "tl_base_tests")

# -----------------------------------------------------------------------------

set(${EXE_NAME}_SOURCE_FILES
  "tl_common_tests.cpp"
  "tl_exception_tests.cpp"
  "tl_platform_tests.cpp"
  "tl_pointer_tests.cpp"
  "tl_getter_setter_tests.cpp"
  "tl_types_tests.cpp"

  "tl_base_tests.cpp"
  )

# -----------------------------------------------------------------------------

tl_add_executable(
  EXE_NAME
    ${EXE_NAME}
  SOURCE_FILES
    ${${EXE_NAME}_SOURCE_FILES}
  )

# -----------------------------------------------------------------------------
