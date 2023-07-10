#pragma once
#include "intrinsic/size.h"
#include "range.h"
#include "r_iter.h"
#include "wrapper/wrapper.h"

template<>
struct size_impl<half_open_range_tag>
{
	template<typename R>
	struct apply
	{
	   using pos1_=R::start;
	   using pos2_=R::finish;
	   using type=long_<pos2_::value-pos1_::value>;
	};
};