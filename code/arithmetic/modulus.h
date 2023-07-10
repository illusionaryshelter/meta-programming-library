#pragma once
#include "miscellaneous/aux_type.h"
#include "wrapper/integral_c.h"
#include "type_traits/mpl_type_traits.h"
#include "composition/placeholder.h"
#include "apply/apply.h"
#include "processor/processor.h"
#include "composition/arity.h"
#include "lambda/lambda.h"
#include "composition/template_arity.h"
#include "miscellaneous/if_.h"
#include "miscellaneous/numeric_cast.h"
#include "miscellaneous/rank.h"
#include "miscellaneous/tag.h"





template<typename Tag1, typename Tag2>
struct modulus_impl :if_c<(Tag1::value > Tag2::value),
	cast_2nd_impl<modulus_impl<Tag1, Tag1>, Tag1, Tag2>,
	cast_1st_impl<modulus_impl<Tag2, Tag2>, Tag1, Tag2>>::type
{};
template<>
struct modulus_impl<integral_c_tag, integral_c_tag>
{
	template<typename T1, typename T2>
	struct apply :integral_c<typename largest_int<typename T1::value_type,
		typename T2::value_type>::type,
		T1::value% T2::value>
	{};
};
template<>struct modulus_impl<na, na>
{
	template<typename U1, typename U2>
	struct apply
	{
		using type = apply;
		constexpr static int value = 0;
	};
};
template<typename Tag>
struct modulus_impl<na, Tag>
{
	template<typename U1, typename U2>
	struct apply
	{
		using type = apply;
		constexpr static int value = 0;
	};
};
template<typename Tag>
struct modulus_impl<Tag, na>
{
	template<typename U1, typename U2>
	struct apply
	{
		using type = apply;
		constexpr static int value = 0;
	};
};
template<typename T>struct modulus_tag
{
	using type = tag<T>::type;
};
template<PP_DEFAULT_PARAMS__2(typename T), typename T3 = na, typename T4 = na, typename T5 = na>
struct modulus :modulus<modulus<modulus<modulus<T1, T2>, T3>, T4>, T5 >
{
	using  arity = int_<5>;
	using arg0 = T1;
	using arg1 = T2;
	using arg2 = T3;
	using arg3 = T4;
	using arg4 = T5;
	struct rebind
	{
		template<PP_DEFAULT_PARAMS__5(typename T)>
		struct apply : modulus<PP_DEFAULT_PARAMS__5(T)> {};
	};
};
template<PP_DEFAULT_PARAMS__4(typename T)>
struct modulus<T1, T2, T3, T4, na> :modulus<modulus<modulus<T1, T2>, T3>, T4>
{
	using  arity = int_<5>;
	using arg0 = T1;
	using arg1 = T2;
	using arg2 = T3;
	using arg3 = T4;
	using arg4 = na;
	struct rebind
	{
		template<PP_DEFAULT_PARAMS__4(typename T)>
		struct apply : modulus<PP_DEFAULT_PARAMS__4(T), na> {};
	};
};
template<PP_DEFAULT_PARAMS__3(typename T)>
struct modulus<T1, T2, T3, na, na> : modulus<modulus<T1, T2>, T3>
{
	using  arity = int_<5>;
	using arg0 = T1;
	using arg1 = T2;
	using arg2 = T3;
	using arg3 = na;
	using arg4 = na;
	struct rebind
	{
		template<PP_DEFAULT_PARAMS__3(typename T)>
		struct apply : modulus<PP_DEFAULT_PARAMS__3(T), na, na> {};
	};
};
template<PP_DEFAULT_PARAMS__2(typename T)>
struct modulus<T1, T2, na, na, na>
	:modulus_impl<typename modulus_tag<T1>::type,
	typename modulus_tag<T2>::type
	>::template apply<T1, T2>::type
{
	using  arity = int_<5>;
	using arg0 = T1;
	using arg1 = T2;
	using arg2 = na;
	using arg3 = na;
	using arg4 = na;
	struct rebind
	{
		template<PP_DEFAULT_PARAMS__2(typename T)>
		struct apply : modulus<PP_DEFAULT_PARAMS__2(T), na, na, na> {};
	};
};
template<>
struct modulus<na, na>
{
	template<PP_DEFAULT_PARAMS__5(typename T)>
	struct apply :modulus<PP_DEFAULT_PARAMS__5(T)> {};
};
template<>
struct modulus<int, int>
{
	using type = int;
	enum { value = 0 };
};
template<typename Tag>
struct lambda<modulus<na, na>, Tag, int_<-1>>
{
	using is_le = false_;
	using result_ = modulus<na, na>;
	using type = modulus<na, na>;
};
template<int N>
struct arity<modulus<na, na>, N> :int_<5>
{};
template<PP_DEFAULT_PARAMS__5(typename T)>
struct template_arity<modulus<PP_DEFAULT_PARAMS__5(T)>> :int_<5>
{};
template<>
struct template_arity<modulus<na, na>> : int_<-1>
{};