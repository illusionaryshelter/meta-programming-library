#pragma once
#include "intrinsic/back.h"
#include "v_at.h"
#include "iteration/iterator.h"
#include "vector0.h"


template<long N>
struct back_impl<vector_tag<N>>
{
   template <typename Vec>
   struct apply
   {
	   using type=typename Vec::back;
   };
};

