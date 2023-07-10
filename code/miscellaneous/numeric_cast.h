#pragma once
#include "apply/apply.h"
#include "apply/apply_impl.h"
template<typename SourceTag, typename TargetTag>
struct numeric_cast
{
	template<typename N>
	struct apply;
};
template<typename F, typename Tag1, typename Tag2>
struct cast_1st_impl
{
	template<typename T1, typename T2>
	struct apply :apply_wrap2<F,
		typename apply_wrap1<numeric_cast<Tag1, Tag2>, T1>::type,
		T2>
	{};
};
template<typename F, typename Tag1, typename Tag2>
struct cast_2nd_impl
{
	template<typename T1, typename T2>
	struct apply :apply_wrap2<F, T1,
		typename apply_wrap1<numeric_cast<Tag2, Tag1>, T2>::type>
	{};
};