#pragma once
#include "miscellaneous/aux_type.h"
#include "processor/processor.h"
template<typename First , typename Last >
struct iter_range;
struct iter_range_tag {};

template<typename First = na, typename Last = na>
struct iter_range
{
	using tag= iter_range_tag;
	using type= iter_range;
	using begin=First;
	using end=Last;
    using arity = int_<2>;
    using arg0 = First;
    using arg1 = Last;
    struct rebind
    {
        template<PP_DEFAULT_PARAMS__2(typename T)>
        struct apply : iter_range<PP_DEFAULT_PARAMS__2(T)> {};
    };
};

