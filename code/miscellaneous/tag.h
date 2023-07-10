#pragma once
#include "aux_type.h"
#include "wrapper/wrapper.h"
#include "if_.h"
#include "type_traits/mpl_type_traits.h"



template<typename T>
struct tag_impl
{
	using type=typename T::tag;
};
template<typename T,typename Default=void_>
struct tag
   :if_c<has_tag<T> ,tag_impl<T>,Default>::type
{};