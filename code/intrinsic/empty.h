#pragma once
#include "type_traits/mpl_type_traits.h"
#include "begin_end.h"
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"
template <typename Tag>
struct empty_impl
{
	template<typename S>
	struct apply:is_same<
	typename begin<S>::type,
	typename end<S>::type>
	{};
};
template <typename Seq=na>
struct empty:empty_impl<typename tag<Seq>::type>::template apply<Seq>
{};