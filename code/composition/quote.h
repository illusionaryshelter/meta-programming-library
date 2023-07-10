#pragma once
#include "type_traits/mpl_type_traits.h"
#include "wrapper/wrapper.h"
#include "miscellaneous/aux_type.h"
#include "processor/processor.h"
template<typename T, bool has_type_>
struct quote_impl
{
	using type = typename T::type;
};
template<typename T>
struct quote_impl<T, false>
{
	using type = T;
};

//#define QUOTEN_GENERATE(i_) \
//	template<template<PP_CAT(PP_DEFAULT_PARAMS__,i_)(typename P)>class F,typename Tag=void_>\
//	struct PP_CAT(quote,i_)\
//	{\
//		template<PP_CAT(PP_DEFAULT_PARAMS__,i_)(typename U)>struct apply\
//		{\
//			using type=typename quote_impl<\
//			                  F<PP_CAT(PP_DEFAULT_PARAMS__,i_)(U)>,\
//							  has_type<F<PP_CAT(PP_DEFAULT_PARAMS__,i_)(U)>>::value>::type;\
//		};\
//	};

template<template<typename P1>class F, typename Tag = void_> struct 
quote1 {
	template<typename U1>struct apply {
		using type = 
		typename quote_impl< F<U1>, has_type<F<U1>>>::type;
	};
};
template<template<typename P1, typename P2>class F, typename Tag = void_> 
struct quote2 {
	template<typename U1, typename U2>struct apply {
		using type = 
		typename quote_impl< F<U1, U2>, has_type<F<U1, U2>>>::type;
	};
};
template<template<typename P1, typename P2, typename P3>class F, typename Tag = void_> 
struct quote3 {
	template<typename U1, typename U2, typename U3>struct apply {
		using type = 
		typename quote_impl< F<U1, U2, U3>, has_type<F<U1, U2, U3>>>::type;
	};
};
template<template<typename P1, typename P2, typename P3, typename P4>class F, typename Tag = void_> 
struct quote4 {
	template<typename U1, typename U2, typename U3, typename U4>struct apply {
		using type = 
		typename quote_impl< F<U1, U2, U3, U4>, has_type<F<U1, U2, U3, U4>>>::type;
	};
};
template<template<typename P1, typename P2, typename P3, typename P4, typename P5>class F, typename Tag = void_> 
struct quote5 {
	template<typename U1, typename U2, typename U3, typename U4, typename U5>struct apply {
		using type = 
		typename quote_impl< F<U1, U2, U3, U4, U5>, has_type<F<U1, U2, U3, U4, U5>>>::type;
	};
};
