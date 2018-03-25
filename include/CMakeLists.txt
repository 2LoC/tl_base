# -----------------------------------------------------------------------------

TLOC_INCLUDE("/tl_base_ci/tl_add_ycm_config.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})
TLOC_INCLUDE("/tl_base_ci/tl_add_travis.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})
TLOC_INCLUDE("/tl_base_ci/tl_add_gitignore.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})
TLOC_INCLUDE("/tl_base_ci/tl_add_superbuild.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})
TLOC_INCLUDE("/tl_base_ci/tl_add_setup.cmake" ${tl_base_ci_INCLUDE_DIRECTORIES})

# -----------------------------------------------------------------------------
# superbuild

tl_add_superbuild(DESTINATION "${CMAKE_SOURCE_DIR}/")

# -----------------------------------------------------------------------------
# travis

set(TRAVIS_SCRIPT
"\
  - mkdir build
  - cd build
  - cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_INSTALL_PREFIX=../install -DTLOC_DETAILED_LOGS=ON ../
  - make
  - mkdir build_release
  - cd build_release
  - cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_INSTALL_PREFIX=../install -DTLOC_DETAILED_LOGS=ON ../
  - make
"
)

tl_add_travis(
  LINUX_COMPILERS "clang-3.8;clang-4.0;clang-5.0"
  SCRIPT ${TRAVIS_SCRIPT}
  )

# -----------------------------------------------------------------------------
# gitignore

tl_add_gitignore(
  IGNORE_LIST "*setup*.sh"
  )

# -----------------------------------------------------------------------------
# ycm

tl_add_ycm_config()

# -----------------------------------------------------------------------------
# setup files

tl_add_setup(
  NAME "setup"
  BUILD_DIR "build"
  BUILD_TYPE "Debug"
  DESTINATION ${CMAKE_SOURCE_DIR}
  CL_ARGS ${CL_ARGS}
  )

tl_add_setup(
  NAME "setup_release"
  BUILD_DIR "build_release"
  BUILD_TYPE "Release"
  DESTINATION ${CMAKE_SOURCE_DIR}
  CL_ARGS ${CL_ARGS}
  )

# -----------------------------------------------------------------------------
# project

add_subdirectory(${PROJ_NAME})

if (NOT TLOC_DISABLE_TESTS)
  add_subdirectory(${PROJ_NAME}_tests)
endif()
