#pragma once
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"


template< typename Tag > 
struct pop_front_impl;
template< typename S > 
struct pop_front;

template<typename Tag>
struct pop_front_impl
{
	template<typename S>
	struct apply;
};

template< typename S=na >
struct pop_front
   :pop_front_impl<typename tag<S>::type>
      ::template apply<S>
{};