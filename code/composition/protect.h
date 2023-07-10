#pragma once
#include "aux_type.h"
#include "arity.h"
#include "template_arity.h"
template<typename T, int N>
struct protect;
//
template<typename T = na, int not_le_ = 0>
struct protect :T
{
	using type = protect;
};
//
template<int N, typename T>
struct arity<protect<T>, N> :arity<T, N> {};
//
template<>
struct protect<na>
{
	template<typename T1>
	struct apply :protect<T1> {};
};
template<typename T0>
struct template_arity<protect<T0>> :int_<1> {};
template<>
struct template_arity<protect<na>> :int_<-1> {};