#pragma once
#include "begin_end.h"
#include "iteration/iterator.h"
#include "miscellaneous/tag.h"
template <typename Tag>
struct front_impl
{
	template <typename Seq>
	struct apply
	{
		using iter_=typename begin<Seq>;
		using type=typename deref<iter_>::type;
	};
};
template<typename Seq=na>
struct front
:front_impl<typename tag<Seq>::type>::template apply<Seq>
{};