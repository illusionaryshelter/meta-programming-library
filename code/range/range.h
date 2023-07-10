#pragma once
#include "wrapper/integral_c.h"
#include "r_iter.h"
#include "r_back.h"
#include "r_empty.h"
#include "r_front.h"
#include "r_size.h"

template<typename T,T s,T f>
struct range_c
{
	using tag=half_open_range_tag;
	using value_type=T;
	using type=range_c;

	using start=integral_c<T,s>;
	using finish=integral_c<T,f>;

	using begin=r_iter<start>;
	using end=r_iter<finish>;
};

