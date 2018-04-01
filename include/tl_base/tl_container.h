#pragma once

#include <array>
#include <tl_base/tl_assert.h>

namespace tl { namespace core {

  // -----------------------------------------------------------------------
  // macros for quickly exposing begin/end/size/empty of containers

#define TLOC_DECL_AND_DEF_CONTAINER_BEGIN_CONST(_suffix_, _container_)\
  auto begin ## _suffix_(int = 0) const -> decltype(_container_.begin()) \
  { return _container_.begin(); }

#define TLOC_DECL_AND_DEF_CONTAINER_END_CONST(_suffix_, _container_)\
  auto  end ## _suffix_(int = 0) const -> decltype(_container_.end()) \
  { return _container_.end(); }

#define TLOC_DECL_AND_DEF_CONTAINER_BEGIN(_suffix_, _container_)\
  auto begin ## _suffix_(int = 0) -> decltype(_container_.begin()) \
  { return _container_.begin(); }

#define TLOC_DECL_AND_DEF_CONTAINER_END(_suffix_, _container_)\
  auto end ## _suffix_(int = 0) -> decltype(_container_.end()) \
  { return _container_.end(); }

#define TLOC_DECL_AND_DEF_CONTAINER_SIZE(_suffix_, _container_)\
  auto size ## _suffix_(int = 0) const -> decltype(_container_.size()) \
  { return _container_.size(); }

#define TLOC_DECL_AND_DEF_CONTAINER_EMPTY(_suffix_, _container_)\
  bool empty ## _suffix_(int = 0) const { return _container_.empty(); }

#define TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END_CONST(_suffix_, _container_)\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN_CONST(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_END_CONST(_suffix_, _container_)

#define TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END(_suffix_, _container_)\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_END(_suffix_, _container_)

#define TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END_ALL(_suffix_, _container_)\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END_CONST(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END(_suffix_, _container_)

#define TLOC_DECL_AND_DEF_CONTAINER_SIZE_AND_EMPTY(_suffix_, _container_)\
  TLOC_DECL_AND_DEF_CONTAINER_EMPTY(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_SIZE(_suffix_, _container_)

#define TLOC_DECL_AND_DEF_CONTAINER_CONST_METHODS(_suffix_, _container_)\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END_CONST(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_SIZE_AND_EMPTY(_suffix_, _container_)

#define TLOC_DECL_AND_DEF_CONTAINER_ALL_METHODS(_suffix_, _container_)\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_BEGIN_END_CONST(_suffix_, _container_);\
  TLOC_DECL_AND_DEF_CONTAINER_SIZE_AND_EMPTY(_suffix_, _container_)

  // -----------------------------------------------------------------------
  // Compile time index and coord calculator

  // ///////////////////////////////////////////////////////////////////////
  // Index2D

  template <int t_size_x, int t_size_y, int t_coord_x = -1, int t_coord_y = -1>
  struct index_2d
  {
    static_assert(t_coord_x < t_size_x, "Index is out of bounds");
    static_assert(t_coord_y < t_size_y, "Index is out of bounds");

    static constexpr int value = t_coord_x + t_size_y * t_coord_y;
  };

  template <int t_size_x, int t_size_y>
  struct index_2d<t_size_x, t_size_y, -1, -1>
  {
    static int get(int x, int y)
    {
      static_assert(x < t_size_x, "Index x is out of bounds");
      static_assert(y < t_size_y, "Index y is out of bounds");

      return x + t_size_x * y;
    }
  };

  template <typename T>
  int
    GetIndex(std::array<T, 2> a_grid_size, std::array<T, 2> a_coord)
  {
    TLOC_ASSERT(a_coord[0] < a_grid_size[0], "Index x is out of bounds");
    TLOC_ASSERT(a_coord[1] < a_grid_size[1], "Index y is out of bounds");

    return core_utils::CastNumber<int>
      (a_coord[0] + a_gridSize[0] * a_coord[1]);
  }

  // ///////////////////////////////////////////////////////////////////////
  // Index3D

  template <int T_SizeX  , int T_SizeY  , int T_SizeZ,
            int T_CoordX = -1, int T_CoordY = -1, int T_CoordZ = -1>
  struct Index3D
  {
    TLOC_STATIC_ASSERT(T_CoordX < T_SizeX, Index_is_out_of_bounds);
    TLOC_STATIC_ASSERT(T_CoordY < T_SizeY, Index_is_out_of_bounds);
    TLOC_STATIC_ASSERT(T_CoordZ < T_SizeZ, Index_is_out_of_bounds);

    enum { k_value = T_CoordX + T_SizeX * T_CoordY + T_SizeX * T_SizeY * T_CoordZ };
  };

  template <int T_SizeX, int T_SizeY, int T_SizeZ>
  struct Index3D<T_SizeX, T_SizeY, T_SizeZ, -1, -1, -1>
  {
    static int Get(int x, int y, int z)
    {
      TLOC_ASSERT(x < T_SizeX, "Index x is out of bounds");
      TLOC_ASSERT(y < T_SizeY, "Index y is out of bounds");
      TLOC_ASSERT(z < T_SizeZ, "Index y is out of bounds");

      return x + T_SizeX * y + T_SizeX * T_SizeY * z;
    }
  };

  template <typename T>
  int
    GetIndex(core_ds::Tuple<T, 3> a_gridSize,
             core_ds::Tuple<T, 3> a_coord)
  {
    TLOC_ASSERT(a_coord[0] < a_gridSize[0], "Index x is out of bounds");
    TLOC_ASSERT(a_coord[1] < a_gridSize[1], "Index y is out of bounds");
    TLOC_ASSERT(a_coord[2] < a_gridSize[2], "Index y is out of bounds");

    return core_utils::
      CastNumber<int>(a_coord[0] +
                         a_gridSize[0] * a_coord[1] +
                         a_gridSize[0] * a_gridSize[1] * a_coord[2]);
  }

  // ///////////////////////////////////////////////////////////////////////
  // Coord2D

  template <int T_SizeX, int T_SizeY, int T_Index = -1>
  struct Coord2D
  {
    TLOC_STATIC_ASSERT(T_Index < T_SizeX * T_SizeY, Index_out_of_bounds);

    enum { k_x = T_Index % T_SizeX };
    enum { k_y = (T_Index / T_SizeX) % T_SizeY};
  };

  template <int T_SizeX, int T_SizeY>
  struct Coord2D<T_SizeX, T_SizeY, -1>
  {
    static core_ds::Tuple2s Get(int a_index)
    {
      TLOC_ASSERT(a_index < T_SizeX * T_SizeY, "Index out of bounds");
      return core_ds::MakeTuple(a_index % T_SizeX,
                                (a_index / T_SizeX) % T_SizeY);
    }

    template <typename T>
    static core_ds::Tuple<T, 2> Get(T a_index)
    {
      TLOC_ASSERT(a_index < T_SizeX * T_SizeY, "Index out of bounds");
      return core_ds::MakeTuple<T>(a_index % T_SizeX,
                                   (a_index / T_SizeX) % T_SizeY);
    }
  };

  template <typename T>
  core_ds::Tuple<T, 2>
    GetCoord(core_ds::Tuple<T, 2> a_gridSize,
             T a_index)
  {
    TLOC_ASSERT(a_index < a_gridSize[0] * a_gridSize[1], "Index out of bounds");
    return core_ds::MakeTuple(a_index % a_gridSize[0],
                              (a_index / a_gridSize[0]) % a_gridSize[1]);
  }

  // ///////////////////////////////////////////////////////////////////////
  // Coord3D

  template <int T_SizeX, int T_SizeY, int T_SizeZ, int T_Index = -1>
  struct Coord3D
  {
    TLOC_STATIC_ASSERT(T_Index < T_SizeX * T_SizeY * T_SizeZ, Index_out_of_bounds);

    enum { k_x = T_Index % T_SizeX };
    enum { k_y = ( T_Index / T_SizeX ) % T_SizeY };
    enum { k_z = ( ( T_Index / T_SizeX) / T_SizeY ) % T_SizeZ };
  };

  template <int T_SizeX, int T_SizeY, int T_SizeZ>
  struct Coord3D<T_SizeX, T_SizeY, T_SizeZ, -1>
  {
    static core_ds::Tuple3s Get(int a_index)
    {
      TLOC_ASSERT(a_index < T_SizeX * T_SizeY * T_SizeZ, "Index out of bounds");
      return core_ds::MakeTuple(a_index % T_SizeX,
                                (a_index / T_SizeX) % T_SizeY,
                                ((a_index / T_SizeX) / T_SizeY) % T_SizeZ);
    }

    template <typename T>
    static core_ds::Tuple<T, 3> Get(T a_index)
    {
      TLOC_ASSERT(a_index < T_SizeX * T_SizeY * T_SizeZ, "Index out of bounds");
      return core_ds::MakeTuple<T>(a_index % T_SizeX,
                                   (a_index / T_SizeX) % T_SizeY,
                                   ((a_index / T_SizeX) / T_SizeY) % T_SizeZ);
    }
  };

  template <typename T>
  core_ds::Tuple<T, 3>
    GetCoord(core_ds::Tuple<T, 3> a_gridSize,
             T a_index)
  {
      TLOC_ASSERT(a_index < a_gridSize[0] * a_gridSize[1] * a_gridSize[2],
                  "Index out of bounds");
      return core_ds::MakeTuple<T>
        (a_index % a_gridSize[0],
         (a_index / a_gridSize[0]) % a_gridSize[1],
         ((a_index / a_gridSize[0]) / a_gridSize[1]) % a_gridSize[2]);
  }

  // -----------------------------------------------------------------------
  // Runtime index calculator



};}
