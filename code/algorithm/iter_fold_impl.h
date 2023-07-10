#pragma once
#include "iteration/basic_iterator.h"
#include "apply/apply.h"
#define UNROLLING 4

template<int N,typename First,typename Last,typename State,typename ForwardOp>
struct iter_fold_impl;

template<typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<0, First, Last, State, ForwardOp>
{
	using iter0=First;
	using state0=State;

	using state=state0;
	using Iter=iter0;
};

template<typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<1, First, Last, State, ForwardOp>
{
	using iter0 = First;
	using state0 = State;
	using state1 = typename apply2<ForwardOp,state0, iter0>::type;
	using iter1=typename next<iter0>::type;

	using state=state1;
	using Iter = iter1;
};

template<typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<2, First, Last, State, ForwardOp>
{
	using iter0 = First;
	using state0 = State;
	using state1 = typename apply2<ForwardOp, state0, iter0>::type;
	using iter1 = typename next<iter0>::type;
	using state2= typename apply2<ForwardOp, state1, iter1>::type;
	using iter2 = typename next<iter1>::type;

	using state = state2;
	using Iter = iter2;
};

template<typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<3, First, Last, State, ForwardOp>
{
	using iter0 = First;
	using state0 = State;
	using state1 = typename apply2<ForwardOp, state0, iter0>::type;
	using iter1 = typename next<iter0>::type;
	using state2 = typename apply2<ForwardOp, state1, iter1>::type;
	using iter2 = typename next<iter1>::type;
	using state3 = typename apply2<ForwardOp, state1, iter2>::type;
	using iter3 = typename next<iter2>::type;

	using state = state3;
	using Iter = iter3;
};

template<typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<UNROLLING, First, Last, State, ForwardOp>
{
	using iter0 = First;
	using state0 = State;
	using state1 = typename apply2<ForwardOp, state0, iter0>::type;
	using iter1 = typename next<iter0>::type;
	using state2 = typename apply2<ForwardOp, state1, iter1>::type;
	using iter2 = typename next<iter1>::type;
	using state3 = typename apply2<ForwardOp, state1, iter2>::type;
	using iter3 = typename next<iter2>::type;
	using state4 = typename apply2<ForwardOp, state1, iter3>::type;
	using iter4 = typename next<iter3>::type;

	using state = state4;
	using Iter = iter4;
};

template<int N, typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl
{
	using chunk_=
	iter_fold_impl<UNROLLING,First,Last,State,ForwardOp>;
	using res_=
	iter_fold_impl<((N-UNROLLING)< 0 ? 0 : N-UNROLLING),typename chunk_::Iter,Last,typename chunk_::state,ForwardOp>;
	using state=
	typename res_::state;
	using Iter=
	typename res_::Iter;
};

template<typename First, typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<-1,First,Last,State,ForwardOp>
: iter_fold_impl<-1,typename next<First>::type,Last,typename apply2<ForwardOp,State,First>::type,ForwardOp>
{};

template<typename Last, typename State, typename ForwardOp>
struct iter_fold_impl<-1, Last, Last, State, ForwardOp>
{
	using state=State;
	using Iter=Last;
};