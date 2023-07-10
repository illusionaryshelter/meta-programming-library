#pragma once
#include "type_traits/mpl_type_traits.h"
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"

template< typename Tag > 
struct push_back_impl;
template< typename S, typename T > 
struct push_back;

struct has_push_back_tag{};

template <typename Tag>
struct push_back_impl
{
	template<typename S,typename T>
	struct apply
	{};
};

template <typename Tag>
struct has_push_back_impl
{
	template<typename S>
	struct apply
	   :bool_<has_type<push_back<S,has_push_back_tag>>>
	{};
};

template< typename S=na, typename T =na>
struct push_back
    :push_back_impl<typename tag<S>::type>
	   ::template apply<S,T>
{};

template<typename S=na>
struct has_push_back
   :has_push_back_impl<typename tag<S>::type>
      ::template apply<S>
{};