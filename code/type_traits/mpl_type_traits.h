#pragma once
#include "miscellaneous/aux_type.h"
#include "wrapper/integral_c.h"
#include "wrapper/wrapper.h"
#include "miscellaneous/if_.h"
#include <concepts>

template<class T, T val>
struct integral_constant
{
	using tag = integral_c_tag;
	using value_type = T;
	using type = integral_constant<T, val>;
	static constexpr T value = val;
	operator const integral_c<T, val>& ()const
	{
		static const char data[sizeof(long)] = { 0 };
		static const void* pdata = data;
		return *(reinterpret_cast<const integral_c<T, val>*>(pdata));
	}
	operator T()const { return val; }
};
template<class T, T val>
T const integral_constant<T, val>::value;
template<bool val>
struct integral_constant<bool, val>
{
	using tag = integral_c_tag;
	using value_type = bool; ;
	using type = integral_constant<bool, val>;
	static const bool value = val;

	operator const bool_<val>& ()const
	{
		static const char data[sizeof(long)] = { 0 };
		static const void* pdata = data;
		return *(reinterpret_cast<const bool_<val>*>(pdata));
	}
	operator bool()const { return val; }
};
template <bool val>
bool const integral_constant<bool, val>::value;
template <bool val>
using bool_constant=integral_constant<bool, val>;
using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！


//is_reference
template <class T>struct is_lvalue_reference :public false_type {};
template <class T>struct is_lvalue_reference<T&> :public true_type {};
template <class T> struct is_rvalue_reference : public false_type {};
template <class T> struct is_rvalue_reference<T&&> : public true_type {};
template<class T>struct is_reference :public integral_constant<
	bool, is_lvalue_reference<T>::value || is_rvalue_reference<T>::value>
{};
//correlation
template <class T,class U>
struct is_same:public false_type
{};
template <class T>
struct is_same<T,T>:public true_type
{};
template <class T>
struct is_same<T&, T&> :public true_type
{};
template<typename T1>
struct same_as
{
	template<typename T2>
	struct apply
	   :is_same<T1,T2>
	{};
};
template<typename T1>
struct not_same_as
{
	template<typename T2>
	struct apply 
	   :integral_constant<bool, !is_same<T1, T2>::value>
	{};
};


template <class T1,class T2>
struct is_equal
{
   using type=bool_<T1::value==T2::value>;
};

//is sequence
template<class F>
concept is_apply=requires(F){typename F::apply;};
template<class Iter>
concept is_deref=requires(Iter){typename Iter::type;};
template<class Iter>
concept is_next= requires(Iter){typename Iter::next::type;};
template<class Iter>
concept is_category = requires(Iter) { typename Iter::catagory; };
template<class S>
concept is_Iterable=is_category<S>&&is_next<S>&&is_deref<S>;
template<class S>
concept is_bounded =requires(S){typename S::begin; typename S::end;};
template<typename S>
concept has_size=requires(S){typename S::size;};
template<typename S>
concept has_type = requires(S) { typename S::type; };
template<typename S>
concept has_tag = requires(S) { typename S::tag; };