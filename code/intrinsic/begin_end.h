#pragma once
#include "miscellaneous/aux_type.h"
#include "lambda/lambda.h"
#include "miscellaneous/tag.h"
#include "miscellaneous/if_.h"
#include "type_traits/mpl_type_traits.h"
#include "wrapper/wrapper.h"


//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template< typename Tag > struct begin_impl;
template< typename Tag > struct end_impl;

template< typename Tag > 
struct begin_impl
{
	template<typename Seq>
	struct apply
	{
		using type=	typename 
		eval_if<bool_<is_bounded<Seq>>,typename Seq::begin,void_>::type;
	};
};

template< typename Tag >
struct end_impl
{
	template<typename Seq>
	struct apply
	{
		using type = typename
			eval_if<bool_<is_bounded<Seq>>, typename Seq::end, void_>::type;
	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！
template< typename Seq > struct begin;
template< typename Seq > struct end;

template< typename Seq =na> 
struct begin
{
	using tag_=typename tag<Seq>::type;
	using type=typename 
	begin_impl<tag_>::template apply<Seq>::type;
};

template< typename Seq = na>
struct end
{
	using tag_ = typename tag<Seq>::type;
	using type = typename
		end_impl<tag_>::template apply<Seq>::type;
};