#pragma once
#include "v_iter.h"
#include "vector0.h"
#include "intrinsic/begin_end.h"
#include "intrinsic/size.h"

template <long N>
struct begin_impl<vector_tag<N>>
{
	template <typename Vec>
	struct apply
	{
		using type=v_iter<Vec,0>; 
    };
};

template<long N>
struct end_impl<vector_tag<N>>
{
	template <typename Vec>
	struct apply
	{
		using type=v_iter<Vec,size<Vec>::value>;
	};
};

