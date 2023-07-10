#pragma once
#include "iter_fold_impl.h"
#include "miscellaneous/aux_type.h"
#include "type_traits/mpl_type_traits.h"
#include "miscellaneous/if_.h"
#include "wrapper/wrapper.h"
#include "lambda/lambda.h"
#include "intrinsic/begin_end.h"

template <class S>
struct __size:if_c<has_size<S>,typename S::size,long_<-1>>{};

template<typename Seq=na,typename State=na,typename ForwardOp=na>
struct iter_fold
{
   using type=typename 
   iter_fold_impl<__size<Seq>::value,
   typename begin<Seq>::type,
   typename end<Seq>::type,
   State,
   typename lambda<ForwardOp>::type
   >::state;
};