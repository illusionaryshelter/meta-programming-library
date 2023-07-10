#pragma once
#include "vector_n.h"
#include "wrapper/integral_c.h"
#include "processor/processor.h"
/*
  Vec_n_c Implement ,n from 0 to 5
  If you want to extend
  Just Copy or make a generator by Macro
*/
#define VEC_MEM(i_) \
using type=PP_CAT(PP_CAT(vector,i_),_c);\
using value_type=T

template<typename T, PP_DEFAULT_PARAMS__1(T C)>
struct vector1_c
    : vector1< integral_c< T, C1 > >
{
    VEC_MEM(1);
};
template<typename T, PP_DEFAULT_PARAMS__2(T C)>
struct vector2_c
    : vector2< integral_c< T, C1 >,integral_c< T, C2 > >
{
    VEC_MEM(2);
};
template<typename T, PP_DEFAULT_PARAMS__3(T C)>
struct vector3_c
    : vector3< integral_c< T, C1 >,integral_c< T, C2 >,integral_c< T, C3 > >
{
    VEC_MEM(3);
};
template<typename T, PP_DEFAULT_PARAMS__4(T C)>
struct vector4_c
    : vector4< integral_c< T, C1 >,integral_c< T, C2 >,integral_c< T, C3 > ,integral_c< T, C4 > >
{
    VEC_MEM(4);
};
template<typename T, PP_DEFAULT_PARAMS__5(T C)>
struct vector5_c
    : vector5< integral_c< T, C1 >,integral_c< T, C2 >,integral_c< T, C3 > ,integral_c< T, C4 > ,integral_c< T, C5 >>
{
    VEC_MEM(5);
};