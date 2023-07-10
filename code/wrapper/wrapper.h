#pragma once
#include <iostream>
#include "integral_c.h"
#include "aux_type.h"
template<int N>
using int_ = integral_c<int, N>;
template<long N>
using long_ = integral_c<long, N>;
template<unsigned int N>
using uint_ = integral_c<unsigned int, N>;
template<std::size_t N>
using size_t_ = integral_c<std::size_t, N>;
using false_ = bool_<false>;
using true_ = bool_<true>;
//
template<typename T>
struct wrapped_type;
template<typename T>	
struct wrapped_type<type_wrapper<T>>
{
	using type = T;
};
