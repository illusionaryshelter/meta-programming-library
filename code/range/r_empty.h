#pragma once
#include "range.h"
#include "r_iter.h"
#include "type_traits/mpl_type_traits.h"
#include "intrinsic/empty.h"
template<>
struct empty_impl<half_open_range_tag>
{
	template<typename R>
	struct apply
	   :is_equal<typename R::start,typename R::finish>
	{};
};