#pragma once
#include "vector0_c.h"
#include "vector_n_c.h"
#include "processor/processor.h"
#include <limits.h>
template<typename T,PP_DEFAULT_PARAMS_5(long long C,LLONG_MAX)>
struct vector_c;

template<typename T>
struct vector_c<T, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX>
	:vector0_c<T>
{
	using type=typename vector0_c<T>::type;
};

template<typename T, PP_DEFAULT_PARAMS__1(long long C)>
struct vector_c<T, C1, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX>
	:vector1_c<T,(T)C1>
{
	using type = typename vector1_c<T,(T)C1>::type;
};

template<typename T, PP_DEFAULT_PARAMS__2(long long C)>
struct vector_c<T, C1, C2, LLONG_MAX, LLONG_MAX, LLONG_MAX>
	:vector2_c<T, (T)C1,(T)C2>
{
	using type = typename vector2_c<T, (T)C1, (T)C2>::type;
};

template<typename T, PP_DEFAULT_PARAMS__3(long long C)>
struct vector_c<T, C1, C2, C3, LLONG_MAX, LLONG_MAX>
	:vector3_c<T, (T)C1, (T)C2,(T)C3>
{
	using type = typename vector3_c<T, (T)C1, (T)C2,(T)C3>::type;
};

template<typename T, PP_DEFAULT_PARAMS__4(long long C)>
struct vector_c<T, C1, C2, C3, C4, LLONG_MAX>
	:vector4_c<T, (T)C1, (T)C2, (T)C3,(T)C4>
{
	using type = typename vector4_c<T, (T)C1, (T)C2, (T)C3,(T)C4>::type;
};

template<typename T, PP_DEFAULT_PARAMS__5(long long C)>
struct vector_c
	:vector5_c<T, (T)C1, (T)C2, (T)C3, (T)C4,(T)C5>
{
	using type = typename vector5_c<T, (T)C1, (T)C2, (T)C3, (T)C4, (T)C5>::type;
};