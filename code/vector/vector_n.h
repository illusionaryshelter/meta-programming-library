#pragma once
#include "v_iter.h"
#include "vector0.h"
#include "iteration/iterator.h"
#include "iteration/iterator_tag.h"
#include "v_at.h"
#include "v_back.h"
#include "v_begin_end.h"
#include "v_clear.h"
#include "v_empty.h"
#include "v_front.h"
#include "v_size.h"
#include "intrinsic/pop_back.h"
#include "intrinsic/pop_front.h"
#include "intrinsic/push_back.h"
#include "intrinsic/push_front.h"

/*
  Vec_n Implement ,n from 0 to 5
  If you want to extend
  Just Copy or make a generator by Macro  
  Some discipline write in Vector1
*/

template<typename V>
struct v_at<V, 0>
{
	using type=typename V::item0;
};
template <typename T0>
struct vector1
{
	using tag=vector_tag<1>;
	using type=vector1;
	using item0=T0;
	using item1=void_;
	using back=T0;
	using begin=v_iter<type,0>;
	using end=v_iter<type,1>;
};
template<>
struct push_front_impl< vector_tag<0> >
{
	/*
	   if vector_n::size::value=n
	   shouldn't afford specialization
	*/
	template< typename Vec, typename T >
	struct apply
	{
		using  type=vector1<T> ;
	};
};
template<>
struct pop_front_impl< vector_tag<1> >
{
	/*
	    if vector_n::size::value=0
		shouldn't afford specialization
    */
	template< typename Vec > 
	struct apply
	{
		using type= vector0<> ;
	/*
	pop_front & pop_back should afford mem named pop_type
	if __POP_RETURN is defined
	*/
    #ifdef  __POP_RETURN
        using pop_type = typename Vec::item0;
    #endif // __POP_RETURN
	};
};
template<>
struct push_back_impl< vector_tag<0> >
{
	/*
	   if vector_n::size::value=n
	   shouldn't afford specialization
	*/
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector1<T> ;
	};
};
template<>
struct pop_back_impl< vector_tag<1> >
{
	/*
		 if vector_n::size::value=0
		  shouldn't afford specialization
	*/
	template< typename Vec > struct apply
	{
		using type=vector0<>;
	/*
	pop_front & pop_back should afford mem named pop_type
	if __POP_RETURN is defined
	*/
#ifdef __POP_RETURN
		using pop_type = typename Vec::item0;
#endif // __POP_RETURN

	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！
template< typename V >
struct v_at< V, 1 >
{
	using type= typename V::item1 ;
};
template<typename T0, typename T1>
struct vector2
{
	using tag=vector_tag<2> ;
	using type=vector2 ;
	using item0=T0 ;
	using item1=T1 ;

	using item2=void_ ;
	using back= T1 ;
	using begin=v_iter< type, 0 > ;
	using end=v_iter< type, 2 > ;
};
template<>
struct push_front_impl< vector_tag<1> >
{  
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector2<T,typename Vec::item0> ;
	};
};
template<>
struct pop_front_impl< vector_tag<2> >
{
	template< typename Vec > 
	struct apply
	{
		using type=vector1<typename Vec::item1> ;
#ifdef __POP_RETURN
        using pop_type =typename Vec::item0;
#endif // __POP_RETURN
	};
};
template<>
struct push_back_impl< vector_tag<1> >
{
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector2<typename Vec::item0,T> ;
	};
};
template<>
struct pop_back_impl< vector_tag<2> >
{
	template< typename Vec >
	struct apply
	{
		using type= vector1<typename Vec::item0> ;
#ifdef __POP_RETURN
        using pop_type =typename Vec::item1;
#endif // __POP_RETURN
	};
};
//！！！！！！！！！！！！！！！！！！！！
template< typename V >
struct v_at< V, 2 >
{
	using type= typename V::item2;
};
template<typename T0, typename T1, typename T2>
struct vector3
{
	using tag=vector_tag<3> ;
	using type=vector3 ;
	using item0=T0 ;
	using item1=T1 ;
	using item2=T2 ;

	using item3=void_ ;
	using back=T2 ;
	using begin=v_iter< type, 0 > ;
	using end=v_iter< type, 3 > ;
};
template<>
struct push_front_impl< vector_tag<2> >
{
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector3<
		   T,
		   typename Vec::item0, 
		   typename Vec::item1> ;
	};
};
template<>
struct pop_front_impl< vector_tag<3> >
{
	template< typename Vec > 
	struct apply
	{
		using type= vector2<
		   typename Vec::item1, 
		   typename Vec::item2> ;
#ifdef __POP_RETURN
		using pop_type = typename Vec::item0;
#endif // __POP_RETURN

	};
};
template<>
struct push_back_impl< vector_tag<2> >
{
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector3<
		   typename Vec::item0, 
		   typename Vec::item1,
		   T> ;
	};
};
template<>
struct pop_back_impl< vector_tag<3> >
{
	template< typename Vec > 
	struct apply
	{
		using type= vector2<
		   typename Vec::item0, 
		   typename Vec::item1> ;
#ifdef __POP_RETURN
		using pop_type = typename Vec::item2;
#endif // __POP_RETURN
	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！
template< typename V >
struct v_at< V, 3 >
{
	using type= typename V::item3;
};
template<typename T0, typename T1, typename T2, typename T3>
struct vector4
{
	using tag=vector_tag<4> ;
	using type=vector4 ;
	using item0=T0 ;
	using item1=T1 ;
	using item2=T2 ;
	using item3=T3 ;

	using item4=void_ ;
	using back=T3 ;
	using begin=v_iter< type, 0 > ;
	using end=v_iter< type, 4 > ;
};
template<>
struct push_front_impl< vector_tag<3> >
{
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector4<
		   T,
		   typename Vec::item0,
		   typename Vec::item1,
		   typename Vec::item2> ;
	};
};
template<>
struct pop_front_impl< vector_tag<4> >
{
	template< typename Vec > 
	struct apply
	{
		using type= vector3<
		   typename Vec::item1, 
		   typename Vec::item2, 
		   typename Vec::item3> ;
#ifdef __POP_RETURN
		using pop_type = typename Vec::item0;
#endif // __POP_RETURN
	};
};
template<>
struct push_back_impl< vector_tag<3> >
{
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector4<
	    	typename Vec::item0, 
	      	typename Vec::item1, 
	    	typename Vec::item2,T> ;
	};
};
template<>
struct pop_back_impl< vector_tag<4> >
{
	template< typename Vec > 
	struct apply
	{
		using type= vector3<
	    	typename Vec::item0, 
	    	typename Vec::item1, 
	    	typename Vec::item2> ;
#ifdef __POP_RETURN
		using pop_type=typename Vec::item3;
#endif // __POP_RETURN

	};
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template< typename V >
struct v_at< V, 4 >
{
	using type= typename V::item4 ;
};
template<typename T0, typename T1, typename T2, typename T3, typename T4>
struct vector5
{
	using tag=vector_tag<5> ;
	using type=vector5 ;
	using item0=T0 ;
	using item1=T1 ;
	using item2=T2 ;
	using item3=T3 ;
	using item4=T4 ;

	using item5=void_ ;
	using back=T4 ;
	using begin=v_iter< type, 0 > ;
	using end=v_iter< type, 5 > ;
};
template<>
struct push_front_impl< vector_tag<4> >
{
	template< typename Vec, typename T >
	struct apply
	{
		using type= vector5<
		   T,
		   typename Vec::item0, 
		   typename Vec::item1, 
		   typename Vec::item2, 
		   typename Vec::item3> ;
	};
};
template<>
struct pop_front_impl< vector_tag<5> >
{
	template< typename Vec > 
	struct apply
	{
		using type= vector4<
		    typename Vec::item1, 
			typename Vec::item2, 
			typename Vec::item3, 
			typename Vec::item4> ;
#ifdef __POP_RETURN
		using pop_type=Vec::item0;
#endif // __POP_RETURN

	};
};
template<>
struct push_back_impl< vector_tag<4> >
{
	template< typename Vec, typename T > 
	struct apply
	{
		using type= vector5<
			typename Vec::item0, typename Vec::item1, 
			typename Vec::item2, typename Vec::item3,
			T> ;
	};
};
template<>
struct pop_back_impl< vector_tag<5> >
{
	template< typename Vec > 
	struct apply
	{
		using type= vector4<
			typename Vec::item0,
			typename Vec::item1, 
			typename Vec::item2, 
			typename Vec::item3> ;
#ifdef __POP_RETURN
		using pop_type=Vec::item4;
#endif // __POP_RETURN

	};
};
