#pragma once
#include "composition/placeholder.h"
#include "processor/processor.h"
#include "miscellaneous/aux_type.h"
#include "apply_fwd.h"
#include "apply_impl.h"
#include "lambda/lambda.h"
template<typename F>
struct apply0 :apply_wrap0<typename lambda<F>::type>
{
    using arity = int_<1>;
    using arg0 = F;
    struct rebind
    {
        template <typename U0>
        struct apply : apply0<U0>
        {};
    };
};
template<typename F>
struct apply<F, na, na, na, na, na> :apply0<F>
{};
//
template<typename F, PP_DEFAULT_PARAMS__1(typename T)>
struct apply1 :apply_wrap1<typename lambda<F>::type, PP_DEFAULT_PARAMS__1(T)>
{
    using arity = int_<2>;
    using arg0 = F;
    using arg1 = T1;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__2(typename U)>
        struct apply :apply1< PP_DEFAULT_PARAMS__2(U) >
        {};
    };
};
template<typename F, typename T1>
struct apply<F, T1, na, na, na, na> :apply1<F, T1>
{};
//
template<typename F, PP_DEFAULT_PARAMS__2(typename T)>
struct apply2 :apply_wrap2<typename lambda<F>::type, PP_DEFAULT_PARAMS__2(T)>
{
    using arity = int_<3>;
    using arg0 = F;
    using arg1 = T1;
    using arg3 = T2;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__3(typename U)>
        struct apply :apply2< PP_DEFAULT_PARAMS__3(U) >
        {};
    };
};
template<typename F, PP_DEFAULT_PARAMS__2(typename T)>
struct apply<F, T1, T2, na, na, na> :apply2<F, T1, T2>
{};
//
template<typename F, PP_DEFAULT_PARAMS__3(typename T)>
struct apply3 :apply_wrap3<typename lambda<F>::type, PP_DEFAULT_PARAMS__3(T)>
{
    using arity = int_<4>;
    using arg0 = F;
    using arg1 = T1;
    using arg3 = T2;
    using arg4 = T3;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__4(typename U)>
        struct apply :apply3< PP_DEFAULT_PARAMS__4(U) >
        {};
    };
};
template<typename F, PP_DEFAULT_PARAMS__3(typename T)>
struct apply<F, T1, T2, T3, na, na> :apply3<F, T1, T2, T3>
{};
//
template<typename F, PP_DEFAULT_PARAMS__4(typename T)>
struct apply4 :apply_wrap4<typename lambda<F>::type, PP_DEFAULT_PARAMS__4(T)>
{
    using arity = int_<5>;
    using arg0 = F;
    using arg1 = T1;
    using arg3 = T2;
    using arg4 = T3;
    using arg5 = T4;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__5(typename U)>
        struct apply :apply4< PP_DEFAULT_PARAMS__5(U) >
        {};
    };
};
template<typename F, PP_DEFAULT_PARAMS__4(typename T)>
struct apply<F, T1, T2, T3, T4, na> :apply4<F, T1, T2, T3, T4>
{};
//
template<typename F, PP_DEFAULT_PARAMS__5(typename T)>
struct apply5 :apply_wrap5<typename lambda<F>::type, PP_DEFAULT_PARAMS__5(T)>
{
    using arity = int_<6>;
    using arg0 = F;
    using arg1 = T1;
    using arg3 = T2;
    using arg4 = T3;
    using arg5 = T4;
    using arg5 = T5;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__6(typename U)>
        struct apply :apply5< PP_DEFAULT_PARAMS__6(U) >
        {};
    };
};

template<typename F, PP_DEFAULT_PARAMS__5(typename T)>
struct apply :apply5<F, T1, T2, T3, T4,T5>
{};