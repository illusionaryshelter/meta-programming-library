#pragma once
#include "wrapper/wrapper.h"
#include "miscellaneous/aux_type.h"
#include "iteration/iterator.h"
#include "miscellaneous/tag.h"
#include "v_iter.h"
#include <limits.h>

template<long N>
struct vector_tag;


//！！！！！！！！！！！！！！！！！！

template <typename T=na>
struct vector0;

template<>
struct vector0<na>
{
	using tag=vector_tag<0>;
	using type=vector0;
	using item0=void_;
	using size=long_<0>;
};