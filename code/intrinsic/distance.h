#pragma once
#include "miscellaneous/if_.h"
#include "arithmetic/comparison.h"
#include "arithmetic/assignment.h"
#include "apply/apply_impl.h"
#include "miscellaneous/tag.h"
#include "wrapper/wrapper.h"
#include "algorithm/iter_fold.h"
#include "type_traits/mpl_type_traits.h"
#include "iteration/iterator_range.h"





//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

template<typename Tag>
struct distance_impl;
template<typename Tag>
struct distance_impl
{
	template<typename First,typename Last>
	struct apply
	{
		using type=typename 
		iter_fold<iter_range<First,Last>,
		long_<0>,
		next<>
		>::type;
		constexpr static long value=type::value;
	};
};

//！！！！！！！！！！！！！！！！！！！！
