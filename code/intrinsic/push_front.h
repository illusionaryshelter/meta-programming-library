#pragma once
#include "type_traits/mpl_type_traits.h"
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"
struct has_push_front_tag{};
template< typename Tag > struct push_front_impl;
template< typename Seq, typename T > struct push_front;
//


template<typename Tag>
struct push_front_impl
{
	template<typename Seq,typename T>
	struct apply
	{};
};

template<typename Tag>
struct has_push_front_impl
{
	template<typename Seq>
	struct apply:bool_<has_type<push_front<Seq,has_push_front_tag>>>
	{};
};

//
template <typename Seq=na,typename T=na>
struct push_front
   :push_front_impl<typename tag<Seq>::type>
      ::template apply<Seq,T>
{};

template<typename Seq=na>
struct has_push_front
	: has_push_front_impl< typename tag<Seq>::type >
	::template apply< Seq >
{};