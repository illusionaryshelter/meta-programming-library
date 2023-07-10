#pragma once
#include "iteration/iterator_tag.h"
#include "iteration/iterator.h"
#include "arithmetic/plus.h"

struct half_open_range_tag;
struct r_iter_tag;
template<typename N>
struct r_iter;

template<typename N>
struct r_iter
{
	using tag= r_iter_tag;
	using category=random_access_iterator_tag;
	using type=N;
	using next=r_iter<typename next<N>::type>;
	using prior=r_iter<typename prior<N>::type>;
};
//！！！！！！！！！！！！！！！！！！！！！！
template <>
struct advance_impl<r_iter_tag>
{
	template<typename Iter,typename Dis>
	struct apply
	{
		using n_=typename deref<Iter>::type;
		using m_=typename plus<n_,Dis>::type;
		using result_=integral_c<
		    typename n_::value_type,
			m_::value>;
		using type=r_iter<result_>;
	};
};

template<>
struct distance_impl<r_iter_tag>
{
    template<typename Iter1,typename Iter2>
	struct apply
	{
		using pos1_=typename Iter1::type;
		using pos2_=typename Iter2::type;
		using type=long_<pos2_::value-pos1_::value>;
	};
};