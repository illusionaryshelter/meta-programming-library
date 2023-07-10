#pragma once
#include "arity.h"
#include "wrapper/wrapper.h"
template<typename F, int N>
struct template_arity_impl
{
	const int static value = sizeof(arity_helper(type_wrapper<F>(), arity_tag<N>())) - 1;
};
template<typename F>
struct template_arity {
	const static int value = max_arity< template_arity_impl<F, 1>::value,
	template_arity_impl<F, 2>::value,
	template_arity_impl<F, 3>::value,
	template_arity_impl<F, 4>::value,
	template_arity_impl<F, 5>::value,
	template_arity_impl<F, 6>::value>::value;
	using type = int_<value>;
};

#define ARITY_TEMPLATE_BIND(i,name)\
template<PP_CAT(PP_DEFAULT_PARAMS__,i)(typename T)>\
struct template_arity<name<PP_CAT(PP_DEFAULT_PARAMS__,i)(T)>>\
:int_<i>{};