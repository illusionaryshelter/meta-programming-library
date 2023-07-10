#pragma once
#include "distance.h"
#include "begin_end.h"
#include "miscellaneous/tag.h"

template< typename Tag > 
struct size_impl;
template< typename Tag >
struct size_impl
{
	template<typename Seq>
	struct apply
	{
		using type=typename 
		distance<typename begin<Seq>::type,typename end<Seq>::type>::type;
	};
};

//！！！！！！！！！！！！！！！！！！！！！！！！！！

template< typename Seq > 
struct size;
template< typename Seq >
struct size:size_impl<typename tag<Seq>::type>::template apply<Seq>::type
{};