#pragma once
#include "iteration/iterator.h"
#include "intrinsic/seq_intrins.h"
#include "iteration/iterator_range.h"
#include "algorithm/fold.h"
#include "composition/placeholder.h"


template< typename Tag > struct insert_impl;
template< typename S, typename Pos, typename T > struct insert;
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename Seq, typename Op>
struct inserter
{
	using state=Seq;
	using operation=Op;
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename Tag>
struct insert_impl
{
	template<typename S,typename Pos,typename T>
	struct apply
	{
		using half_1_= iter_range<typename begin<S>::type,Pos>;
		using half_2_=iter_range<Pos,typename end<S>::type>;
		using half_seq_=typename fold<half_2_,
		   typename clear<S>::type,
		   push_back<_,_> >::type;
		using type=typename fold<half_1_,
		   typename push_back<half_seq_,T>::type,
		   push_back<_,_> >::type;
	};
};

template<> struct insert_impl<void_>
{
	template<PP_DEFAULT_PARAMS__3(typename T)> 
	struct apply
	{};
};
template<> struct insert_impl<int>
{
	template< PP_DEFAULT_PARAMS__3(typename T)> 
	struct apply
	{
		using type = int;
	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename S=na, typename Pos=na, typename T=na>
struct insert
	:insert_impl<typename tag<S>::type>
	   ::template apply<S, Pos, T>
{
	using arity = int_<3>;
	using arg0 = S;
	using arg1 = Pos;
	using arg2 = T;
	struct rebind
	{
		template<PP_DEFAULT_PARAMS__3(typename T)>
		struct apply : insert<PP_DEFAULT_PARAMS__3(T)> {};
	};
};



//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename S>
struct back_inserter
   :inserter<S,push_front<_,_>>
{};

template<typename S>
struct front_inserter
	:inserter<S, push_back<_,_>>
{};