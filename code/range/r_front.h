#pragma once
#include "intrinsic/front.h"
#include "range.h"
#include "r_iter.h"
template<>
struct front_impl<half_open_range_tag>
{
	template<typename R>
	struct apply
	{
		using type=typename R::start;
	};
};