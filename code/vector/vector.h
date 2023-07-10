#pragma once
#include "vector_n.h"
#include "vector0.h"
#include "miscellaneous/aux_type.h"
#include "processor/processor.h"
#include "vector_c.h"

template<PP_DEFAULT_PARAMS_5(typename T,na)> 
struct vector;

template<>
struct vector<na,na,na,na,na>
	:vector0<>
{
	using type=vector0<>::type;
};

template<typename T1>
struct vector<T1, na, na, na, na>
	:vector1<T1>
{
	using type=typename vector1<T1>::type;
};

template<PP_DEFAULT_PARAMS__2(typename T)>
struct vector<T1, T2, na, na, na>
	:vector2<T1,T2>
{
	using type = typename vector2<T1, T2>::type;
};
template <PP_DEFAULT_PARAMS__3(typename T)>
struct vector<T1, T2, T3, na, na>
	:vector3<T1, T2, T3>
{
	using type = typename vector3<T1, T2,T3>::type;
};
template <PP_DEFAULT_PARAMS__4(typename T)>
struct vector<T1, T2, T3, T4, na>
	:vector4<T1, T2, T3,T4>
{
	using type = typename vector4<T1, T2, T3,T4>::type;
};
template <PP_DEFAULT_PARAMS__5(typename T)>
struct vector
	:vector5<T1, T2, T3, T4,T5>
{
	using type = typename vector5<T1, T2, T3, T4,T5>::type;
};





















