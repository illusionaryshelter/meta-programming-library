#pragma once
#include "basic_iterator.h"
#include "miscellaneous/aux_type.h"
#include "wrapper/wrapper.h"
template<class Iterator = na>
struct prior {
    using type = typename Iterator::prior;
    using arity = int_<1>;
    using arg0 = Iterator;
    struct rebind
    {
        template<typename U0>
        struct apply :prior<U0> {};
    };
};
template<>
struct prior<na>
{
    template<typename T>struct apply :prior<T> {};
};