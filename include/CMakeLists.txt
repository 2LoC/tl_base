# -----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.1)

# -----------------------------------------------------------------------------

find_package(tl_base_ci REQUIRED)
get_target_property(tl_base_ci_INCLUDE_DIRECTORIES tl_base_ci
  INTERFACE_INCLUDE_DIRECTORIES
  )

# -----------------------------------------------------------------------------

include("${tl_base_ci_INCLUDE_DIRECTORIES}/tl_base_ci/tl_common.cmake")
include("${tl_base_ci_INCLUDE_DIRECTORIES}/tl_base_ci/tl_add_ycm_config.cmake")
include("${tl_base_ci_INCLUDE_DIRECTORIES}/tl_base_ci/tl_add_travis.cmake")
include("${tl_base_ci_INCLUDE_DIRECTORIES}/tl_base_ci/tl_add_gitignore.cmake")
include("${tl_base_ci_INCLUDE_DIRECTORIES}/tl_base_ci/tl_add_superbuild.cmake")

# -----------------------------------------------------------------------------
# superbuild

tl_add_superbuild(DESTINATION "${CMAKE_SOURCE_DIR}/../")

# -----------------------------------------------------------------------------
# travis

set(TRAVIS_SCRIPT
"\
  - mkdir build
  - cd build
  - cmake -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_INSTALL_PREFIX=../install -DTLOC_DETAILED_LOGS=ON ../
  - make
  - cd ../include/
  - mkdir build
  - cd build
  - cmake -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_INSTALL_PREFIX=../install -DTLOC_DETAILED_LOGS=ON ../
"
)

tl_add_travis(
  LINUX_COMPILERS "clang-3.8;clang-4.0;clang-5.0"
  DESTINATION "${CMAKE_SOURCE_DIR}/../"
  SCRIPT ${TRAVIS_SCRIPT}
  )

# -----------------------------------------------------------------------------
# gitignore

tl_add_gitignore(
  DESTINATION "${CMAKE_SOURCE_DIR}/../"
  )

# -----------------------------------------------------------------------------
# ycm

tl_add_ycm_config(
  DESTINATION "${CMAKE_SOURCE_DIR}/../"
  )

# -----------------------------------------------------------------------------
# project

set(PROJ_NAME tl_base)
project(${PROJ_NAME})

add_subdirectory(${PROJ_NAME})
