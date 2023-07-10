#pragma once
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"

template <typename Tag>
struct clear_impl
{
	template<typename S>
	struct apply;
};
template<typename S=na>
struct clear
   :clear_impl<typename tag<S>::type>
      ::template apply<S>
{};