#pragma once
#include "wrapper/wrapper.h"


struct vec_iter_tag;

struct forward_iterator_tag :int_<0>
{
	using type=forward_iterator_tag;
};

struct bidirectional_iterator_tag :int_<1>
{
	using type = bidirectional_iterator_tag;
};

struct random_access_iterator_tag :int_<2>
{
	using type = random_access_iterator_tag;
};