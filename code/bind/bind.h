#pragma once
#include "bind_fwd.h"
#include "composition/arity.h"
#include "apply/apply.h"
#include "composition/template_arity.h"
#include "processor/processor.h"
#include "composition/quote.h"
#include "miscellaneous/if_.h"
template<typename T, typename Arg>
struct replace_unnamed_arg
{
	using next = Arg;
	using type = T;
};
template<typename Arg>
struct replace_unnamed_arg<arg<-1>, Arg>
{
	using next = typename Arg::next;
	using type = Arg;
};

template<typename T, PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg
{
	using type = T;
};
template<typename T>struct is_bind_template;
template<int N, PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<arg<N>, PP_DEFAULT_PARAMS__5(U)>
{
	using type = typename apply_wrap5<arg<N>, PP_DEFAULT_PARAMS__5(U)>::type;
};

template<typename F, PP_DEFAULT_PARAMS__5(typename T), PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<bind<F, PP_DEFAULT_PARAMS__5(T)>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind<F, PP_DEFAULT_PARAMS__5(T)>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>::type;
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename F>
struct bind0
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using r0 = replace_unnamed_arg<F, arg<1>>;
		using a0 = typename r0::type;
		using n1 = typename r0::next;
		using f_ = typename resolve_bind_arg<a0, PP_DEFAULT_PARAMS__5(U)>::type;
	public:
		using type = typename apply_wrap0<f_>::type;
	};
};
template<typename F, PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg < bind0<F>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind0<F>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>::type;
};
ARITY_BIND(1, bind0)
ARITY_TEMPLATE_BIND(1, bind0)
template<typename F>
struct bind<F, na, na, na, na, na> :bind0<F> {};
template<typename F, typename T1>
struct bind1
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using r0 = replace_unnamed_arg<F, arg<1>>;
		using a0 = typename r0::type;
		using n1 = typename r0::next;
		using f_ = typename resolve_bind_arg<a0, PP_DEFAULT_PARAMS__5(U)>::type;
		//
		using r1 = replace_unnamed_arg<T1, n1>;
		using a1 = typename r1::type;
		using n2 = typename r1::next;
		using t1 = resolve_bind_arg<a1, PP_DEFAULT_PARAMS__5(U)>;
	public:
		using type = typename apply_wrap1<f_, typename t1::type>::type;
	};
};
template<typename F, typename T1, PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<bind1<F, T1>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind1<F, T1>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>::type;
};
ARITY_BIND(2, bind1)
ARITY_TEMPLATE_BIND(2, bind1)
template<typename F, typename T1>
struct bind<F, T1, na, na, na, na> :bind1<F, T1> {};
template<typename F, typename T1, typename T2>
struct bind2
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using r0 = replace_unnamed_arg< F, arg<1> >;
		using a0 = typename r0::type;
		using n1 = typename r0::next;
		using f_ = typename resolve_bind_arg< a0, U1, U2, U3, U4, U5 >::type;
		//
		using r1 = replace_unnamed_arg< T1, n1 >;
		using a1 = typename r1::type;
		using n2 = typename r1::next;
		using t1 = resolve_bind_arg< a1, U1, U2, U3, U4, U5 >;
		//
		using r2 = replace_unnamed_arg< T2, n2 >;
		using a2 = typename r2::type;
		using n3 = typename r2::next;
		using t2 = resolve_bind_arg< a2, U1, U2, U3, U4, U5 >;
	public:
		using type = typename apply_wrap2<f_, typename t1::type, typename t2::type>::type;
	};
};
template<typename F, typename T1, typename T2, PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<bind2<F, T1, T2>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind2<F, T1, T2>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>::type;
};
ARITY_BIND(3, bind2)
ARITY_TEMPLATE_BIND(3, bind2)
template<typename F, typename T1, typename T2>
struct bind<F, T1, T2, na, na, na> :bind2<F, T1, T2> {};
template<typename F, PP_DEFAULT_PARAMS__3(typename T)>
struct bind3
{
	template<PP_DEFAULT_PARAMS_5(typename U, na) >
	struct apply
	{
	private:
		using  r0 = replace_unnamed_arg< F, arg<1> >;
		using  a0 = typename r0::type;
		using  n1 = typename r0::next;
		using  f_ = typename resolve_bind_arg< a0, PP_DEFAULT_PARAMS__5(U) >::type;
		///
		using  r1 = replace_unnamed_arg< T1, n1 >;
		using  a1 = typename r1::type;
		using  n2 = typename r1::next;
		using  t1 = resolve_bind_arg< a1, PP_DEFAULT_PARAMS__5(U) >;
		///
		using  r2 = replace_unnamed_arg< T2, n2 >;
		using  a2 = typename r2::type;
		using  n3 = typename r2::next;
		using  t2 = resolve_bind_arg< a2, U1, U2, U3, U4, U5 >;
		///
		using  r3 = replace_unnamed_arg< T3, n3 >;
		using  a3 = typename r3::type;
		using  n4 = typename r3::next;
		using  t3 = resolve_bind_arg< a3, U1, U2, U3, U4, U5 >;
	public:
		using type = typename apply_wrap3<f_, typename t1::type, typename t2::type, typename t3::type>::type;
	};
};
template<typename F, PP_DEFAULT_PARAMS__3(typename T), PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<bind3<F, PP_DEFAULT_PARAMS__3(T)>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind3<F, PP_DEFAULT_PARAMS__3(T)>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>::type;
};
ARITY_BIND(4, bind3)
ARITY_TEMPLATE_BIND(4, bind3)
template<typename F, typename T1, typename T2, typename T3>
struct bind<F, T1, T2, T3, na, na> :bind3<F, T1, T2, T3> {};
template<typename F, PP_DEFAULT_PARAMS__4(typename T)>
struct bind4
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using  r0 = replace_unnamed_arg< F, arg<1> >;
		using  a0 = typename r0::type;
		using  n1 = typename r0::next;
		using  f_ = typename resolve_bind_arg< a0, U1, U2, U3, U4, U5 >::type;
		///
		using  r1 = replace_unnamed_arg< T1, n1 >;
		using  a1 = typename r1::type;
		using  n2 = typename r1::next;
		using  t1 = resolve_bind_arg< a1, U1, U2, U3, U4, U5 >;
		///
		using  r2 = replace_unnamed_arg< T2, n2 >;
		using  a2 = typename r2::type;
		using  n3 = typename r2::next;
		using  t2 = resolve_bind_arg< a2, U1, U2, U3, U4, U5 >;
		///
		using  r3 = replace_unnamed_arg< T3, n3 >;
		using  a3 = typename r3::type;
		using  n4 = typename r3::next;
		using  t3 = resolve_bind_arg< a3, U1, U2, U3, U4, U5 >;
		///
		using  r4 = replace_unnamed_arg< T4, n4 >;
		using  a4 = typename r4::type;
		using  n5 = typename r4::next;
		using  t4 = resolve_bind_arg< a4, U1, U2, U3, U4, U5 >;
	public:
		using type = typename apply_wrap4<f_, typename t1::type, typename t2::type, typename t3::type
			, typename t4::type>::type;
	};
};
template<typename F, PP_DEFAULT_PARAMS__4(typename T), PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<bind4<F, PP_DEFAULT_PARAMS__4(T)>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind4<F, PP_DEFAULT_PARAMS__4(T)>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>;
};
ARITY_BIND(5, bind4)
ARITY_TEMPLATE_BIND(5, bind4)
template<typename F, typename T1, typename T2, typename T3, typename T4>
struct bind<F, T1, T2, T3, T4, na> :bind4<F, T1, T2, T3, T4> {};
template<typename F, PP_DEFAULT_PARAMS__5(typename T)>
struct bind5
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using r0 = replace_unnamed_arg< F, arg<1> >;
		using a0 = typename r0::type;
		using n1 = typename r0::next;
		using f_ = typename resolve_bind_arg< a0, U1, U2, U3, U4, U5 >::type;
		///
		using r1 = replace_unnamed_arg< T1, n1 >;
		using a1 = typename r1::type;
		using n2 = typename r1::next;
		using t1 = resolve_bind_arg< a1, U1, U2, U3, U4, U5 >;
		///
		using r2 = replace_unnamed_arg< T2, n2 >;
		using a2 = typename r2::type;
		using n3 = typename r2::next;
		using t2 = resolve_bind_arg< a2, U1, U2, U3, U4, U5 >;
		///
		using r3 = replace_unnamed_arg< T3, n3 >;
		using a3 = typename r3::type;
		using n4 = typename r3::next;
		using t3 = resolve_bind_arg< a3, U1, U2, U3, U4, U5 >;
		///
		using r4 = replace_unnamed_arg< T4, n4 >;
		using a4 = typename r4::type;
		using n5 = typename r4::next;
		using t4 = resolve_bind_arg< a4, U1, U2, U3, U4, U5 >;
		///
		using r5 = replace_unnamed_arg< T5, n5 >;
		using a5 = typename r5::type;
		using n6 = typename r5::next;
		using t5 = resolve_bind_arg< a5, U1, U2, U3, U4, U5 >;
	public:
		using type = typename apply_wrap5<f_, typename t1::type, typename t2::type, typename t3::type
			, typename t4::type, typename t5::type>::type;
	};
};
template<typename F, PP_DEFAULT_PARAMS__5(typename T), PP_DEFAULT_PARAMS__5(typename U)>
struct resolve_bind_arg<bind5<F, PP_DEFAULT_PARAMS__5(T)>, PP_DEFAULT_PARAMS__5(U)>
{
	using f_ = bind5<F, PP_DEFAULT_PARAMS__5(T)>;
	using type = typename apply_wrap5<f_, PP_DEFAULT_PARAMS__5(U)>::type;
};
ARITY_BIND(6, bind5)
ARITY_TEMPLATE_BIND(6, bind5)
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5>
struct bind :bind5<F, T1, T2, T3, T4, T5>
{};
//
template<typename Tag, typename T1, typename T2, typename T3>
struct bind3<quote3<if_, Tag>, T1, T2, T3>
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using n1 = arg<1>;
		using r1 = replace_unnamed_arg<T1, n1>;
		using a1 = typename r1::type;
		using n2 = typename r1::next;
		using t1 = resolve_bind_arg<a1, U1, U2, U3, U4, U5>;

		using r2 = replace_unnamed_arg<T2, n2>;
		using a2 = typename r2::type;
		using n3 = typename r2::next;
		using t2 = resolve_bind_arg<a2, U1, U2, U3, U4, U5>;

		using r3 = replace_unnamed_arg<T3, n3>;
		using a3 = typename r3::type;
		using n4 = typename r3::next;
		using t3 = resolve_bind_arg<a3, U1, U2, U3, U4, U5>;

		using f_ = typename if_<typename t1::type, t2, t3>::type;
	public:
		using type = typename f_::type;
	};
};

template<typename Tag, typename T1, typename T2, typename T3>
struct bind3<quote3<eval_if, Tag>, T1, T2, T3>
{
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
	private:
		using n1 = arg<1>;
		using r1 = replace_unnamed_arg<T1, n1>;
		using a1 = typename r1::type;
		using n2 = typename r1::next;
		using t1 = resolve_bind_arg<a1, U1, U2, U3, U4, U5>;

		using r2 = replace_unnamed_arg<T2, n2>;
		using a2 = typename r2::type;
		using n3 = typename r2::next;
		using t2 = resolve_bind_arg<a2, U1, U2, U3, U4, U5>;

		using r3 = replace_unnamed_arg<T3, n3>;
		using a3 = typename r3::type;
		using n4 = typename r3::next;
		using t3 = resolve_bind_arg<a3, U1, U2, U3, U4, U5>;

		using f_ = typename eval_if<typename t1::type, t2, t3>::type;
	public:
		using type = typename f_::type;
	};
};