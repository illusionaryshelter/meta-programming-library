#pragma once
#include "iteration/iterator.h"
#include "begin_end.h"
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"

template <typename Tag>
struct back_impl
{
	template <typename Seq>
	struct apply
	{
		using end_=typename end<Seq>::type;
		using last_=typename prior<end_>::type;
		using type=typename deref<last_>::type;
	};
};
template <typename S=na>
struct back
   :back_impl<typename tag<S>::type>
      ::template apply<S>
{};