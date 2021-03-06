#pragma once

#include <stdexcept>

namespace tloc { namespace exceptions {

  // Macro for easily defining exceptions
#define TLOC_EXCEPTION_DEFINE(_name_)\
  class _name_ : public std::runtime_error \
  {\
    public:\
      using base_type = std::runtime_error;\
    \
    public:\
    explicit _name_(const std::string& what_arg, long a_line, const char* a_file)\
    : base_type(what_arg)\
    , m_line(a_line)\
    , m_file(a_file)\
    { }\
    explicit _name_(const char* what_arg, long a_line, const char* a_file)\
    : base_type(what_arg)\
    , m_line(a_line)\
    , m_file(a_file)\
    { }\
    \
    public:\
      long  m_line;\
      const char* m_file;\
  }

#define TLOC_EXCEPTION_DEFINE_WITH_INFO(_name_, _info_type_)\
  class _name_ : public std::runtime_error \
  {\
    public:\
      using base_type = runtime_error;\
    \
    public:\
    explicit _name_(const std::string& what_arg, _info_type_ a_info, long int a_line, const char* a_file)\
    : base_type(what_arg)\
    , m_line(a_line)\
    , m_file(a_file)\
    , m_info(std::move(a_info))\
    { }\
    explicit _name_(const char* what_arg, _info_type_ a_info, long int a_line, const char* a_file)\
    : base_type(what_arg)\
    , m_line(a_line)\
    , m_file(a_file)\
    , m_info(std::move(a_info))\
    { }\
    \
    public:\
      long int    m_line;\
      const char* m_file;\
      _info_type_ m_info;\
  }

#define TLOC_THROW_EXCEPTION(_name_, _msg_)\
  throw _name_(_msg_, __LINE__, __FILE__)

#define TLOC_THROW_EXCEPTION_WITH_INFO(_name_, _msg_, _info_)\
  throw _name_(_msg_, _info_, __LINE__, __FILE__)

};};
