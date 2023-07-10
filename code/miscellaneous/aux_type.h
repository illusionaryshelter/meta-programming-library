#pragma once
struct na
{
	using type = na;
	enum { value = 0 };
};
struct void_
{
	using type = void_;
};
template<typename T1, typename T2>
struct pair
{
	using type = pair;
	using first = T1;
	using second = T2;
};
template<typename  T>
struct type_wrapper
{
	using type = T;
};
using no_tag = char(&)[1];
using yes_tag = char(&)[2];


template<int N>
struct arg;

