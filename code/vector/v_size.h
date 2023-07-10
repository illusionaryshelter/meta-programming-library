#pragma once
#include "intrinsic/size.h"
#include "wrapper/wrapper.h"
#include "miscellaneous/tag.h"
#include "vector0.h"

template<long N>
struct size_impl<vector_tag<N>>
{
	template <typename Vec>
	struct apply
	   :long_<N>
	{};
};