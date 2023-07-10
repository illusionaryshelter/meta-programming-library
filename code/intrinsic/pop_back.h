#pragma once
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"

template< typename Tag > 
struct pop_back_impl;
template< typename S > 
struct pop_back;

template< typename Tag >
struct pop_back_impl
{
	template <typename S>
	struct apply;
};

template< typename S=na >
struct pop_back
   :pop_back_impl<typename tag<S>::type>
      ::template apply<S>
{};