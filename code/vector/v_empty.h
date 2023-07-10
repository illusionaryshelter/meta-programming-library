#pragma once
#include "vector0.h"
#include "intrinsic/clear.h"
#include "intrinsic/empty.h"
#include "wrapper/wrapper.h"

template<>
struct empty_impl< vector_tag<0> >
{
    template< typename Vector > struct apply
        : true_
    {};
};

template< long N >
struct empty_impl< vector_tag<N> >
{
    template< typename Vector > struct apply
        : false_
    {};
};