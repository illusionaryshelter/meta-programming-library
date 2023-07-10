#pragma once
#include "intrinsic/clear.h"
#include "v_iter.h"
#include "vector0.h"

template<long N>
struct clear_impl<vector_tag<N>>
{
	template <typename Vec>
	struct apply
	{
	    using type=vector0<>;
	};
};