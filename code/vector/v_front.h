#pragma once
#include "intrinsic/front.h"
#include "v_at.h"
#include "miscellaneous/tag.h"
#include "vector0.h"

template< long N >
struct front_impl< vector_tag<N> >
{
    template< typename Vec> struct apply
    {
        using type= typename Vec::item0;
    };
};