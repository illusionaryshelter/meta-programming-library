#pragma once
#include "apply/apply_impl.h"
#include "miscellaneous/if_.h"
#include "arithmetic/comparison.h"
#include "arithmetic/assignment.h"
#include "miscellaneous/tag.h"
#include "wrapper/wrapper.h"
#include "wrapper/integral_c.h"
#include "iteration/basic_iterator.h"
#define UNROLLING 4
template<typename Iter,typename N>
struct advance;
//
template<long N>
struct advance_forward;
template<>
struct advance_forward<0>
{
	template<typename Iter>
	struct apply
	{
		using iter0=Iter;
		using type=iter0;
	};
};
//
template<>
struct advance_forward<1>
{
	template<typename Iter>
	struct apply
	{
		using iter0 = Iter;
		using iter1=typename next<iter0>::type;
		using type = iter1;
	};
};
//
template<>
struct advance_forward<2>
{
	template< typename Iter > struct apply
	{
		using iter0 = Iter;
		using iter1 = typename next<iter0>::type;
		using iter2 = typename next<iter1>::type;
		using type = iter2;
	};
};
//
template<>
struct advance_forward<3>
{
	template< typename Iter > struct apply
	{
		using iter0 = Iter;
		using iter1 = typename next<iter0>::type;
		using iter2 = typename next<iter1>::type;
		using iter3 = typename next<iter2>::type;
		using type = iter3;
	};
};
//
template<>
struct advance_forward<4>
{
	template< typename Iter > struct apply
	{
		using iter0 = Iter;
		using iter1 = typename next<iter0>::type;
		using iter2 = typename next<iter1>::type;
		using iter3 = typename next<iter2>::type;
		using iter4 = typename next<iter3>::type;
		using type = iter4;
	};
};
//
template<long N>
struct advance_forward
{
	template<typename Iter>
	struct apply
	{
	    using result_=typename apply_wrap1<advance_forward<UNROLLING>,Iter>::type;
		using type=typename apply_wrap1<advance_forward< ((N- UNROLLING )< 0 ? 0 : N- UNROLLING)>,result_>::type;
	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！


template<long N>
struct advance_backward;

template<>
struct advance_backward<0>
{
	template<typename Iter>
	struct apply
	{
		using iter0=Iter;
		using type=iter0;
	};
};
//
template<>
struct advance_backward<1>
{
	template<typename Iter>
	struct apply
	{
		using iter0 = Iter;
		using iter1=typename next<iter0>::type;
		using type = iter1;
	};
};
//
template<>
struct advance_backward<2>
{
	template< typename Iter > struct apply
	{
		using iter0 = Iter;
		using iter1 = typename next<iter0>::type;
		using iter2 = typename next<iter1>::type;
		using type = iter2;
	};
};
//
template<>
struct advance_backward<3>
{
	template< typename Iter > struct apply
	{
		using iter0 = Iter;
		using iter1 = typename next<iter0>::type;
		using iter2 = typename next<iter1>::type;
		using iter3 = typename next<iter2>::type;
		using type = iter3;
	};
};
//
template<>
struct advance_backward<4>
{
	template< typename Iter > struct apply
	{
		using iter0 = Iter;
		using iter1 = typename next<iter0>::type;
		using iter2 = typename next<iter1>::type;
		using iter3 = typename next<iter2>::type;
		using iter4 = typename next<iter3>::type;
		using type = iter4;
	};
};
//

template<long N>
struct advance_backward
{
	template<typename Iter>
	struct apply
	{
		using result_ = typename apply_wrap1<advance_backward<UNROLLING>, Iter>::type;
		using type =typename apply_wrap1 < advance_backward<( (N - UNROLLING )< 0 ? 0 : N - UNROLLING)>, result_>::type;
	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename Tag>
struct advance_impl
{
   template<typename Iter,typename N>
   struct apply
   {
	   using backward_=typename less<N,long_<0>>::type;
	   using offset_=typename if_<backward_, assign<N,-N::value>,N>::type;
	   using f_=typename if_<backward_,advance_backward<offset_::value>,advance_forward<offset_::value>>::type;
	   using type= typename apply_wrap1<f_,Iter>::type ;
   };
};
//
