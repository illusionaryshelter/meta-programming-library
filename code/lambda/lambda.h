#pragma once
#include "composition/protect.h"
#include "miscellaneous/aux_type.h"
#include "lambda_fwd.h"
#include "processor/processor.h"
#include "composition/placeholder.h"
#include "bind/bind.h"
#include "composition/quote.h"
#include "miscellaneous/if_.h"


template<bool C1 = false, bool C2 = false, bool C3 = false, bool C4 = false, bool C5 = false>
struct lambda_or: true_
{};

template<>
struct lambda_or< false, false, false, false, false >: false_
{};

 // namespace aux

template<typename T, typename Tag, typename Arity>
struct lambda
{
	using is_le=false_ ;
	using result_=T ;
	using type=T ;
};

template<typename T>
struct is_lambda_expression: lambda<T>::is_le
{};

template< int N, typename Tag >
struct lambda< arg<N>, Tag, int_< -1 > >
{
	using is_le=true_ ;
	using result_=arg<N> ; //
	using type=protect<result_> ;
};

template<typename F, typename Tag>
struct lambda<bind0<F>, Tag, int_<1>>
{
	using is_le= false_ ;
	using result_=bind0<F> ;
	using type=result_ ;
};


template<typename IsLe, typename Tag, template<typename P1> class F, typename L1>
struct le_result1
{
	using result_ = F<typename L1::type>;
	using type = result_;
};
template<typename Tag, template<typename P1>class F, typename L1>
struct le_result1<true_, Tag, F, L1>
{
	using result_ = bind1<quote1<F, Tag>, typename L1::result_>;
	using type = protect<result_>;
};
template<typename IsLe, typename Tag, template<typename P1, typename P2> class F, typename L1, typename L2>
struct le_result2
{
	using result_ = F<typename L1::type, typename L2::type>;
	using type = result_;
};
template<typename Tag, template<typename P1, typename P2> class F, typename L1, typename L2>
struct le_result2<true_, Tag, F, L1, L2>
{
	using result_ = bind2<quote2<F, Tag>, typename L1::result_, typename L2::result_>;
	using type = protect<result_>;
};
template<typename IsLe, typename Tag, template<typename P1, typename P2, typename P3> class F, typename L1, typename L2, typename L3>
struct le_result3
{
	using result_ = F<typename L1::type, typename L2::type, typename L3::type>;
	using type = result_;
};
template<typename Tag, template<typename P1, typename P2, typename P3> class F, typename L1, typename L2, typename L3>
struct le_result3<true_, Tag, F, L1, L2, L3>
{
	using result_ = bind3<quote3<F, Tag>, typename L1::result_, typename L2::result_, typename L3::result_>;
	using type = protect<result_>;
};
template<typename IsLe, typename Tag, template<typename P1, typename P2, typename P3, typename P4> class F, typename L1, typename L2, typename L3, typename L4>
struct le_result4
{
	using result_ = F<typename L1::type, typename L2::type, typename L3::type, typename L4::type>;
	using type = result_;
};
template<typename Tag, template<typename P1, typename P2, typename P3, typename P4> class F, typename L1, typename L2, typename L3, typename L4>
struct le_result4<true_, Tag, F, L1, L2, L3, L4>
{
	using result_ = bind4<quote4<F, Tag>, typename L1::result_, typename L2::result_, typename L3::result_, typename L4::result_>;
	using type = protect<result_>;
};
template<typename IsLe, typename Tag, template<typename P1, typename P2, typename P3, typename P4, typename P5> class F, typename L1, typename L2, typename L3, typename L4, typename L5>
struct le_result5
{
	using result_ = F<typename L1::type, typename L2::type, typename L3::type, typename L4::type, typename L5::type>;
	using type = result_;
};
template<typename Tag, template<typename P1, typename P2, typename P3, typename P4, typename P5> class F, typename L1, typename L2, typename L3, typename L4, typename L5>
struct le_result5<true_, Tag, F, L1, L2, L3, L4, L5>
{
	using result_ = bind5<quote5<F, Tag>, typename L1::result_, typename L2::result_, typename L3::result_, typename L4::result_, typename L5::result_>;
	using type = protect<result_>;
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<template <typename P1>class F, typename T1, typename Tag>
struct lambda<F<T1>, Tag, int_<1>>
{
	using l1 = lambda<T1, Tag>;
	using is_le1 = typename l1::is_le;
	using is_le = typename lambda_or<is_le1::value>::type;
	using le_result_ = le_result1<is_le, Tag, F, l1>;
	using result_ = typename le_result_::result_;
	using type = le_result_::type;
};
template<typename F, typename T1, typename Tag>
struct lambda<bind1<F, T1>, Tag, int_<2>>
{
	using is_le = false_;
	using result_ = bind1<F, T1>;
	using type = result_;
};


template<template <typename P1, typename P2>class F, typename T1, typename T2, typename Tag>
struct lambda<F<T1, T2>, Tag, int_<2>>
{
	using l1 = lambda<T1, Tag>;
	using l2 = lambda<T2, Tag>;
	using is_le1 = typename l1::is_le;
	using is_le2 = typename l2::is_le;
	using is_le = typename lambda_or<is_le1::value, is_le2::value>::type;
	using le_result_ = le_result2<is_le, Tag, F, l1, l2>;
	using result_ = typename le_result_::result_;
	using type = le_result_::type;
};
template<typename F, typename T1, typename T2, typename Tag>
struct lambda<bind2<F, T1, T2>, Tag, int_<3>>
{
	using is_le = false_;
	using result_ = bind2<F, T1, T2>;
	using type = result_;
};



template<template <typename P1, typename P2, typename P3>class F, typename T1, typename T2, typename T3, typename Tag>
struct lambda<F<T1, T2, T3>, Tag, int_<3>>
{
	using l1 = lambda<T1, Tag>;
	using l2 = lambda<T2, Tag>;
	using l3 = lambda<T3, Tag>;
	using is_le1 = typename l1::is_le;
	using is_le2 = typename l2::is_le;
	using is_le3 = typename l3::is_le;
	using is_le = typename lambda_or<is_le1::value, is_le2::value, is_le3::value>::type;
	using le_result_ = le_result3<is_le, Tag, F, l1, l2, l3>;
	using result_ = typename le_result_::result_;
	using type = le_result_::type;
};
template<typename F, typename T1, typename T2, typename T3, typename Tag>
struct lambda<bind3<F, T1, T2, T3>, Tag, int_<4>>
{
	using is_le = false_;
	using result_ = bind3<F, T1, T2, T3>;
	using type = result_;
};



template<template <typename P1, typename P2, typename P3, typename P4>class F, typename T1, typename T2, typename T3, typename T4, typename Tag>
struct lambda<F<T1, T2, T3, T4>, Tag, int_<4>>
{
	using l1 = lambda<T1, Tag>;
	using l2 = lambda<T2, Tag>;
	using l3 = lambda<T3, Tag>;
	using l4 = lambda <T4, Tag>;
	using is_le1 = typename l1::is_le;
	using is_le2 = typename l2::is_le;
	using is_le3 = typename l3::is_le;
	using is_le4 = typename l4::is_le;
	using is_le = typename lambda_or<is_le1::value, is_le2::value, is_le3::value, is_le4::value>::type;
	using le_result_ = le_result4<is_le, Tag, F, l1, l2, l3, l4>;
	using result_ = typename le_result_::result_;
	using type = le_result_::type;
};
template<typename F, typename T1, typename T2, typename T3, typename T4, typename Tag>
struct lambda<bind4<F, T1, T2, T3, T4>, Tag, int_<5>>
{
	using is_le = false_;
	using result_ = bind4<F, T1, T2, T3, T4>;
	using type = result_;
};


template<template <typename P1, typename P2, typename P3, typename P4, typename P5>class F, typename T1, typename T2, typename T3, typename T4, typename T5, typename Tag>
struct lambda<F<T1, T2, T3, T4, T5>, Tag, int_<5>>
{
	using l1 = lambda<T1, Tag>;
	using l2 = lambda<T2, Tag>;
	using l3 = lambda<T3, Tag>;
	using l4 = lambda <T4, Tag>;
	using l5 = lambda<T5, Tag>;
	using is_le1 = typename l1::is_le;
	using is_le2 = typename l2::is_le;
	using is_le3 = typename l3::is_le;
	using is_le4 = typename l4::is_le;
	using is_le5 = typename l5::is_le;
	using is_le = typename lambda_or<is_le1::value, is_le2::value, is_le3::value, is_le4::value, is_le5::value>::type;
	using le_result_ = le_result5<is_le, Tag, F, l1, l2, l3, l4, l5>;
	using result_ = typename le_result_::result_;
	using type = le_result_::type;
};
template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5, typename Tag>
struct lambda<bind5<F, T1, T2, T3, T4, T5>, Tag, int_<6>>
{
	using is_le = false_;
	using result_ = bind5<F, T1, T2, T3, T4, T5>;
	using type = result_;
};
//
template<typename F, typename Tag1, typename Tag2, typename Arity>
struct lambda<lambda<F, Tag1, Arity>, Tag2, int_<3>>
{
	using l1 = lambda<F, Tag2>;
	using l2 = lambda<Tag1, Tag2>;
	using is_le = typename l1::is_le;
	using arity_ = bind1<quote1<template_arity>, typename l1::result_>;
	using l3 = lambda<typename if_<is_le, arity_, Arity>::type, Tag2>;
	using le_result_ = le_result3<is_le, Tag2, lambda, l1, l2, l3>;
	using result_ = typename le_result_::result_;
	using type = typename le_result_::type;
};
//
template<>
struct lambda<na, na>
{
	template< typename T1, typename T2>
	struct apply
		: lambda<T1,T2>
	{
	};
};
//
template<>
struct lambda<int, int>
{
	typedef int type;
	enum { value = 0 };
};
//
template< typename Tag >
struct lambda< lambda<int, int>, Tag, int_<-1> >
{
	typedef false_ is_le;
	typedef lambda<int, int> result_;
	typedef lambda<int, int> type;
};
//
template< int N >
struct arity< lambda<int, int>, N >: int_< 5 >
{};
//

//
template<>
struct template_arity<lambda<na, na>>: int_<-1>
{};