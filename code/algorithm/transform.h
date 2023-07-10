#pragma once
#include "miscellaneous/aux_type.h"
#include "arithmetic/logic.h"
#include "lambda/lambda.h"
#include "bind/bind.h"
#include "fold.h"
#include "miscellaneous/if_.h"
#include "inserter/insert.h"
#include "type_traits/mpl_type_traits.h"


template<typename Seq, typename Op, typename In>
struct transform1_impl
    : fold<Seq, 
    typename In::state, 
    bind2< typename lambda< typename In::operation >::type,
     _1,
    bind1< typename lambda<Op>::type, _2>
    > >
{};




template<PP_DEFAULT_PARAMS_3( typename P, na)>
struct transform1
    :transform1_impl<PP_DEFAULT_PARAMS__3(P)>
{};

template<PP_DEFAULT_PARAMS__2(typename P)>
struct transform1<P1,P2, na >
    : transform1_impl<P1,P2,
      back_inserter< typename clear<P1>::type > >
{};


template<typename Seq=na, typename Op=na, typename In=na>
struct transform
{
    using type = typename transform1 < Seq, Op, In >::type;
};