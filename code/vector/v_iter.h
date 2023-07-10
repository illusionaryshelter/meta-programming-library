#pragma once
#include "iteration/iterator_tag.h"
#include "intrinsic/at.h"
#include "iteration/basic_iterator.h"
#include "vector0.h"
#include "v_at.h"

template <typename V, long N>
struct v_iter;
//！！！！！！！！！！！！！！！！！！！！
template <typename V, long N>
struct v_iter
{
   using tag=vec_iter_tag;
   using category=random_access_iterator_tag;
   using type=typename v_at<V,N>::type;
   using vector_=V;
   using pos=long_<N>;
   enum {
	   next_=N+1,
	   prior_=N-1,
	   pos_=N
   };
   using next=v_iter<V,next_>;
   using prior=v_iter<V,prior_>;
};

//
template <typename V,long N>
struct next<v_iter<V, N>>
{
	using type=v_iter<V,N+1>;
};
template <typename V, long N>
struct prior<v_iter<V, N>>
{
	using type = v_iter<V, N - 1>;
};
template <typename V,long N,typename Dis>
struct advance<v_iter<V, N>, Dis>
{
	using type=
	v_iter<V,N+Dis::value>;
};
template <typename V,long N,long M>
struct distance<v_iter<V,N>,v_iter<V,M>>
:long_<M-N>
{};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！
