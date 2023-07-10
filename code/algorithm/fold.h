#pragma once
#include "iteration/iterator.h"
#include "apply/apply_impl.h"
#include "type_traits/mpl_type_traits.h"
#include "intrinsic/seq_intrins.h"
#include "miscellaneous/aux_type.h"

template<int N, typename First, typename Last, typename State, typename ForwardOp>
struct fold_impl;
template< typename Op >
struct fold_op;
template< typename Last >
struct fold_pred;

template< typename Op >
struct fold_op
{
    template<typename T1,typename T2>
    struct apply
    {
        using type=typename apply2<Op,T1,
           typename T2::type>::type;
    };
};

template< typename Last >
struct fold_pred
{
    template<typename State, typename Iter>
    struct apply
       :not_same_as<Last>::template apply<Iter>
    {};
};





template<
    typename First, 
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl< 0, First, Last, State, ForwardOp >
{
    using iter0=First ;
    using state0=State ;
    using state=state0 ;
    using Iter=iter0 ;
};

template<
    typename First,
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl< 1, First, Last, State, ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1=typename apply2<ForwardOp,state0,typename deref<iter0>::type>::type;
    using iter1=typename next<iter0>::type;

    using state = state1;
    using Iter = iter1;
};

template<
    typename First,
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl< 2, First, Last, State, ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2<ForwardOp, state0, typename deref<iter0>::type>::type;
    using iter1 = typename next<iter0>::type;
    using state2=typename apply2<ForwardOp, state1, typename deref<iter1>::type>::type;
    using iter2=typename next<iter1>::type;

    using state = state2;
    using Iter = iter2;
};

template<
    typename First,
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl< 3, First, Last, State, ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2<ForwardOp, state0, typename deref<iter0>::type>::type;
    using iter1 = typename next<iter0>::type;
    using state2 = typename apply2<ForwardOp, state1, typename deref<iter1>::type>::type;
    using iter2 = typename next<iter1>::type;
    using state3 = typename apply2<ForwardOp, state2, typename deref<iter2>::type>::type;
    using iter3 = typename next<iter2>::type;

    using state = state3;
    using Iter = iter3;
};

template<
    typename First,
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl< UNROLLING, First, Last, State, ForwardOp >
{
    using iter0 = First;
    using state0 = State;
    using state1 = typename apply2<ForwardOp, state0, typename deref<iter0>::type>::type;
    using iter1 = typename next<iter0>::type;
    using state2 = typename apply2<ForwardOp, state1, typename deref<iter1>::type>::type;
    using iter2 = typename next<iter1>::type;
    using state3 = typename apply2<ForwardOp, state2, typename deref<iter2>::type>::type;
    using iter3 = typename next<iter2>::type;
    using state4 = typename apply2<ForwardOp, state3, typename deref<iter3>::type>::type;
    using iter4 = typename next<iter3>::type;

    using state = state4;
    using Iter = iter4;
};

template<
    int N,
    typename First,
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl
{
    using chunk_=fold_impl<UNROLLING,
       First,
       Last,
       State,
       ForwardOp>;
    using res_=fold_impl<((N-UNROLLING) < 0 ? 0 : N - UNROLLING),
       typename chunk_::Iter,
       Last,
       typename chunk_::state,
       ForwardOp>;
    using state=typename res_::state;
    using Iter=typename res_::Iter;
};

template<
    typename First,
    typename Last,
    typename State,
    typename ForwardOp>
struct fold_impl< -1, First, Last, State, ForwardOp >
   :fold_impl<-1,
   typename next<First>::type,
   Last,
   typename apply2<ForwardOp,State,typename deref<First>::type>::type,
   ForwardOp>
{};

template<
    typename Last, 
    typename State, 
    typename ForwardOp
>
struct fold_impl< -1, Last, Last, State, ForwardOp >
{
    using state= State ;
    using Iter= Last ;
};

template <
   typename Seq=na,
   typename State=na,
   typename ForwardOp=na>
struct fold
{
    using type=typename fold_impl<
       size<Seq>::value,
       typename begin<Seq>::type,
       typename end<Seq>::type,
       State,
       ForwardOp>::state;
    using arity = int_<3>;
    using arg0 = Seq;
    using arg1 = State;
    using arg2 = ForwardOp;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__3(typename T)>
        struct apply : fold<PP_DEFAULT_PARAMS__3(T)> {};
    };
};

template<>
struct fold<na,na,na>
{
    template<PP_DEFAULT_PARAMS__3(typename T)>
    struct apply :fold<PP_DEFAULT_PARAMS__3(T)> 
    {};
};