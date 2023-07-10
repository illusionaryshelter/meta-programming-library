#pragma once
#include "iteration/iterator.h"
#include "intrinsic/back.h"
#include "range.h"
template<>
struct back_impl<half_open_range_tag>
{
	template<typename R>
	struct apply
	{
		using type=typename prior<typename R::finish>::type;
	};
};