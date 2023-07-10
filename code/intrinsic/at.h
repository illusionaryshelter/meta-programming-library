#pragma once
#include "advance.h"
#include "begin_end.h"
#include "iteration/basic_iterator.h"
#include "wrapper/wrapper.h"


template< typename Tag > 
struct at_impl;
template< typename Seq, typename N > 
struct at;
//！！！！！！！！！！！！！！！！！！
template<typename Tag>
struct at_impl
{
	template<typename Seq,typename N>
	struct apply
	{
		using iter_=
		typename advance<typename begin<Seq>::type,N>
		::type;
		using type=typename deref<iter_>::type;
	};
};
//！！！！！！！！！！！！！！！！！！！！
template<typename Seq=na,typename N=na>
struct at
	:at_impl<typename tag<Seq>::type>::template apply<Seq, N>
{};
template<typename Seq,long N>
struct at_c
:at_impl<typename tag<Seq>::type>::template apply<Seq,long_<N>>
{};