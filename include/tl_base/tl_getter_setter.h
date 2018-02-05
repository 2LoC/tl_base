#pragma once

namespace tl {

	///-------------------------------------------------------------------------
	/// Used to avoid code duplication for operators. Requires definition of
	/// operators == and <
	///
	/// @param object The type itself
	///-------------------------------------------------------------------------
#define TLOC_DECLARE_OPERATOR_NOT_EQUAL(object)\
	bool operator !=(object const& a_other) const { return !(operator==(a_other)); }
#define TLOC_DECLARE_OPERATORS(object) \
	TLOC_DECLARE_OPERATOR_NOT_EQUAL(object) \
	bool operator > (object const& a_other) const { return a_other.operator<(*this); }\
	bool operator <=(object const& a_other) const { return !(operator>(a_other)); }\
	bool operator >=(object const& a_other) const { return !(operator<(a_other)); }


	///-------------------------------------------------------------------------
	/// These macros allow you to declare getters and setters quickly. Note that in
	/// this engine member variables should not be accessed directly, even by the
	/// host class itself.
	/// Reason1: to maintain consistency
	/// Reason2: to allow devs to debug get/set operations
	///
	/// The following macros make it easier/quicker to declare and define getters
	/// and setters. The problem ofcourse is that we cannot break into macros. This
	/// is why only declarations are also provided which can be defined immediately
	/// or later by the developer to allow breaking into the getter/setter.
	///------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// Getters

#define TLOC_DECL_GETTER(_type_, _name_)\
	_type_ _name_() const
#define TLOC_DECL_GETTER_NON_CONST(_type_, _name_)\
	_type_ _name_()
#define TLOC_DECL_GETTER_REF(_type_, _name_)\
	_type_&       _name_()
#define TLOC_DECL_GETTER_CONST_REF(_type_, _name_)\
	_type_ const & _name_() const

#define TLOC_DECL_AND_DEF_GETTER(_type_, _name_, _var_)\
	TLOC_DECL_GETTER(_type_, _name_) { return _var_; }

#define TLOC_DECL_AND_DEF_GETTER_NON_CONST(_type_, _name_, _var_)\
	TLOC_DECL_GETTER_NON_CONST(_type_, _name_) { return _var_; }

#define TLOC_DECL_AND_DEF_GETTER_REF(_type_, _name_, _var_)\
	TLOC_DECL_GETTER_REF(_type_, _name_) { return _var_; }
#define TLOC_DECL_AND_DEF_GETTER_CONST_REF(_type_, _name_, _var_)\
	TLOC_DECL_GETTER_CONST_REF(_type_, _name_) { return (_var_); }

	//------------------------------------------------------------------------
	// Setters

#define TLOC_DECL_SETTER(_type_, _name_)\
	void            _name_(_type_ const & a_in)

#define TLOC_DECL_SETTER_CHAIN(_type_, _name_)\
	this_type&      _name_(_type_ const & a_in)

#define TLOC_DECL_SETTER_BY_VALUE(_type_, _name_)\
	void            _name_(_type_ a_in)

#define TLOC_DECL_SETTER_BY_VALUE_CHAIN(_type_, _name_)\
	this_type&      _name_(_type_ a_in)

#define TLOC_DECL_AND_DEF_SETTER(_type_, _name_, _var_)\
	TLOC_DECL_SETTER(_type_, _name_) { _var_ = a_in; }

#define TLOC_DECL_AND_DEF_SETTER_BY_VALUE(_type_, _name_, _var_)\
	TLOC_DECL_SETTER_BY_VALUE(_type_, _name_) { _var_ = a_in; }

#define TLOC_DECL_AND_DEF_SETTER_CHAIN(_type_, _name_, _var_)\
	TLOC_DECL_SETTER_CHAIN(_type_, _name_) { _var_ = a_in; return *this; }

#define TLOC_DECL_AND_DEF_SETTER_BY_VALUE_CHAIN(_type_, _name_, _var_)\
	TLOC_DECL_SETTER_BY_VALUE_CHAIN(_type_, _name_) { _var_ = a_in; return *this; }

	// -----------------------------------------------------------------------
	// For parameters

	// This will declare and define getter/setter with the passed name. It
	// will also return *this (reference of the instance) to allow chaining
	// these methods.
	// NOTE: You need to typedef the class as this_type

	// Variable name is _var_
	// Getter name is _methodName_
	// Setter name is _methodName_

#define TLOC_DECL_PARAM_VAR(_type_, _methodName_, _var_)\
public:\
	this_type& _methodName_(_type_ a_value)\
	{\
		_var_ = a_value;\
		return *this;\
	}\
  _type_ _methodName_() const\
	{\
		return _var_;\
	}\
private:\
	_type_ _var_

#define TLOC_DECL_PARAM_VAR_REF(_type_, _methodName_, _var_)\
public:\
	this_type& _methodName_(const _type_& a_value)\
	{\
		_var_ = a_value;\
		return *this;\
	}\
  const _type_& _methodName_() const\
	{\
		return _var_;\
	}\
private:\
	_type_ _var_

	//------------------------------------------------------------------------
	// Expansions

#define TLOC_DECL_AND_DEF_GETTERS_REF(_type_, _name_, _var_)\
	TLOC_DECL_AND_DEF_GETTER_REF(_type_, _name_, _var_)\
	TLOC_DECL_AND_DEF_GETTER_CONST_REF(_type_, _name_, _var_)
};
