#pragma once
#include "intrinsic/at.h"
#include "wrapper/wrapper.h"

template< typename Vector, long N > 
struct v_at;


template<long N>
struct at_impl<vector_tag<N>>
{
	template<typename Vec, typename N>
	struct apply 
	   :v_at<Vec, N::value>
	{};
};