#pragma once

#include <memory>

namespace tl {

#define TLOC_TYPEDEF_UNIQUE_PTR_NAME(_type_, _typedef_)\
  using _typedef_##_uptr = std::unique_ptr<_type_>;\
  using const_##_typedef_##_uptr = std::unique_ptr<const _type_>

#define TLOC_TYPEDEF_SHARED_PTR_NAME(_type_, _typedef_)\
  using _typedef_##_sptr = std::shared_ptr<_type_>;\
  using const_##_typedef_##_sptr = std::shared_ptr<const _type_>

#define TLOC_TYPEDEF_UNIQUE_PTR(_type_)\
	TLOC_TYPEDEF_UNIQUE_PTR_NAME(_type_, _type_)

#define TLOC_TYPEDEF_SHARED_PTR(_type_)\
	TLOC_TYPEDEF_SHARED_PTR_NAME(_type_, _type_)
};
