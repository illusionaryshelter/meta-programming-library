#pragma once
#include "miscellaneous/if_.h"
#include "wrapper/wrapper.h"
template<typename T1,typename T2>
struct less
{
   using type=bool_<(T1::value<T2::value)>;
};

template<typename T1, typename T2>
struct less_equal
{
	using type = bool_ <( T1::value<=T2::value)>;
};

template<typename T1, typename T2>
struct large
{
	using type = bool_ < (T1::value > T2::value)>;
};

template<typename T1, typename T2>
struct large_equal
{
	using type = bool_ < (T1::value >= T2::value )> ;
};

template<typename T1, typename T2>
struct equal
{
	using type = bool_ <( T1::value == T2::value) >;
};

template<typename T1, typename T2>
struct not_equal
{
	using type = bool_ < (T1::value != T2::value )>;
};