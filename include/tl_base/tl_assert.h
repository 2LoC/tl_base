#pragma once

#include <assert.h>

namespace tl { namespace core {

#define TLOC_ASSERT(_expr_, _msg_)\
  assert(_expr_ && _msg_)

};};
