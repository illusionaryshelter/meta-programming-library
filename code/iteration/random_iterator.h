#pragma once
#include "basic_iterator.h"
#include "bidirectional_iterator.h"
#include "intrinsic/advance.h"
#include "intrinsic/distance.h"
#include "wrapper/wrapper.h"
#include "miscellaneous/aux_type.h"
#include "type_traits/mpl_type_traits.h"
#include "miscellaneous/if_.h"
#include "miscellaneous/tag.h"

template<typename Iter = na, typename N = na>
struct advance 
   :advance_impl<typename tag<Iter>::type>
      ::template apply<Iter, N>
{};
template<typename Iter, long N>
struct advance_c 
   :advance_impl<typename tag<Iter>::type>
      ::template apply<Iter, long_<N>>
{};
//
template<typename First, typename Last>
struct distance;
template<typename First = na, typename Last = na>
struct distance
	:distance_impl<typename if_c<has_tag<First>, typename First::tag, void_>::type>
	   ::template apply<First, Last>
{};