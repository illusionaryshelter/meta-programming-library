#pragma once
#include "aux_type.h"
#include "processor/processor.h"
#include "lambda/lambda.h"
#include "composition/arity.h"
#include "composition/template_arity.h"
template<typename T = na>
struct identity
{
	using type = T;
	using arity = int_<1>;
	using arg0 = T;
	struct rebind
	{
		template <typename U0>
		struct apply : identity<U0>
		{};
	};
};
//
template <int N>
struct arity<identity<na>, N>: int_<5>
{};
//
template<>
struct identity<na>
{
	template <typename T0>
	struct apply
		: identity<T0>
	{
	};
};
//
template <typename Tag>
struct lambda < identity<na>, Tag, int_<-1>>
{
	using is_le = false_;
	using  result_ = identity<na>;
	using type = identity<na>;
};
//
template<>
struct template_arity<identity<na>>:int_<-1>
{};
//
template<typename T1>
struct template_arity<identity<T1>> :int_<1>
{};
//




template<typename T = na>
struct make_identity
{
	using type = identity<T>;
	using arity = int_<1>;
	using arg0 = T;
	struct rebind
	{
		template <typename U0>
		struct apply : make_identity<U0>
		{};
	};
};
//
template<>
struct make_identity<na>
{
	template <typename T0>
	struct apply
		: make_identity<T0>
	{
	};
};
//
template <typename Tag>
struct lambda < make_identity<na>, Tag, int_<-1>>
{
	using  is_le = false_;
	using result_ = make_identity<na>;
	using type = make_identity<na>;
};
//
template <int N>
struct arity<make_identity<na>, N>
	: int_<5>
{};
//
template<>
struct template_arity<make_identity<na>> :int_<-1>
{};
//
template<typename T1>
struct template_arity<make_identity<T1>> :int_<1>
{};