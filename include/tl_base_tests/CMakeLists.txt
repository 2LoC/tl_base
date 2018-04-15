# -----------------------------------------------------------------------------

tl_add_catch()

# -----------------------------------------------------------------------------

set(EXE_NAME "tl_base_tests")

# -----------------------------------------------------------------------------

set(${EXE_NAME}_SOURCE_FILES
  "tl_base_tests.cpp"

  "tl_cast_test.cpp"
  "tl_common_tests.cpp"
  "tl_exception_tests.cpp"
  "tl_getter_setter_tests.cpp"
  "tl_platform_tests.cpp"
  "tl_pointer_tests.cpp"
  "tl_types_tests.cpp"
  )

# -----------------------------------------------------------------------------

tl_add_executable(
  EXE_NAME
    ${EXE_NAME}
  SOURCE_FILES
    ${${EXE_NAME}_SOURCE_FILES}
  LINK_LIBS
    "Catch2::Catch;tl_base"
  BUILD_INTERFACE
    ${PROJECT_SOURCE_DIR}/include/
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  )

add_test(NAME ${EXE_NAME} COMMAND ${EXE_NAME})

# -----------------------------------------------------------------------------
