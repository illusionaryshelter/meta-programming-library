#pragma once
#include "processor/processor.h"
#include "wrapper/wrapper.h"


template<typename T1, int N>
struct arity
{
	static const int value = N;
};

template<int N>
struct arity_tag
{
	using type = char(&)[(unsigned)N + 1];
};

template<PP_DEFAULT_PARAMS__6(int C)>
struct max_arity
{
	const static int value = (C6 > 0 ? C6 : (C5 > 0 ? C5 : (C4 > 0 ? C4 : (C3 > 0 ? C3 : (C2 > 0 ? C2 : (C1 > 0 ? C1 : -1))))));
};

arity_tag<0>::type arity_helper(...);
template<template<PP_DEFAULT_PARAMS__1(typename P)>class F, PP_DEFAULT_PARAMS__1(typename T)>
arity_tag<1>::type arity_helper(type_wrapper<F<PP_DEFAULT_PARAMS__1(T)>>, arity_tag<1>);
template<template<PP_DEFAULT_PARAMS__2(typename P)>class F, PP_DEFAULT_PARAMS__2(typename T)>
arity_tag<2>::type arity_helper(type_wrapper<F<PP_DEFAULT_PARAMS__2(T)>>, arity_tag<2>);
template<template<PP_DEFAULT_PARAMS__3(typename P)>class F, PP_DEFAULT_PARAMS__3(typename T)>
arity_tag<3>::type arity_helper(type_wrapper<F<PP_DEFAULT_PARAMS__3(T)>>, arity_tag<3>);
template<template<PP_DEFAULT_PARAMS__4(typename P)>class F, PP_DEFAULT_PARAMS__4(typename T)>
arity_tag<4>::type arity_helper(type_wrapper<F<PP_DEFAULT_PARAMS__4(T)>>, arity_tag<4>);
template<template<PP_DEFAULT_PARAMS__5(typename P)>class F, PP_DEFAULT_PARAMS__5(typename T)>
arity_tag<5>::type arity_helper(type_wrapper<F<PP_DEFAULT_PARAMS__5(T)>>, arity_tag<5>);
template<template<PP_DEFAULT_PARAMS__6(typename P)>class F, PP_DEFAULT_PARAMS__6(typename T)>
arity_tag<6>::type arity_helper(type_wrapper<F<PP_DEFAULT_PARAMS__6(T)>>, arity_tag<6>);

#define ARITY_TAG_GENERATION(i)\
template<\
    template<PP_CAT(PP_DEFAULT_PARAMS__,i)(typename P)>class F,\
	PP_CAT(PP_DEFAULT_PARAMS__, i)(typename T)>\
typename arity_tag<i>::type \
arity_helper(type_wrapper<F<PP_CAT(PP_DEFAULT_PARAMS__,i)(T)>>,arity_tag<i>);

#define ARITY_BIND(i,name)\
template<int N,PP_CAT(PP_DEFAULT_PARAMS__,i)(typename T)>\
struct arity<name<PP_CAT(PP_DEFAULT_PARAMS__,i)(T)>,N>\
{\
	static const int value=5;\
};
