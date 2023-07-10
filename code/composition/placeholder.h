#pragma once
#include "processor/processor.h"
#include "miscellaneous/aux_type.h"
#include "wrapper/wrapper.h"
#include "template_arity.h"
#include "arity.h"

//#define ARG(i_) \
//    template<>\
//    struct arg<i_>{\
//        static constexpr int value=i_;\
//	    using type=na;\
//    	using tag=na;\
//    	using next= arg<PP_CAT(PP_INC_,i_)>;\
//       	template<PP_DEFAULT_PARAMS_5(typename U, na)>\
//    	struct apply{\
//    		using type=PP_CAT(U,i_);\
//    	};\
//     };\
//     using PP_CAT(_,i_) = arg<i_>;

template<> struct arg<1> {
    static constexpr int value = 1; 
    using type = na; using tag = na; 
    using next = arg<2>; 
    template<typename U1 = na, typename U2 = na, typename U3 = na, typename U4 = na, typename U5 = na> 
    struct apply {
        using type = U1;
    };
}; using _1 = arg<1>;
template<> struct arg<2> {
    static constexpr int value = 2; 
    using type = na; using tag = na; 
    using next = arg<3>; 
    template<typename U1 = na, typename U2 = na, typename U3 = na, typename U4 = na, typename U5 = na> 
    struct apply {
        using type = U2;
    };
}; using _2 = arg<2>;
template<> struct arg<3> {
    static constexpr int value = 3; 
    using type = na; 
    using tag = na; 
    using next = arg<4>; 
    template<typename U1 = na, typename U2 = na, typename U3 = na, typename U4 = na, typename U5 = na> 
    struct apply {
        using type = U3;
    };
}; using _3 = arg<3>;
template<> struct arg<4> {
    static constexpr int value = 4; 
    using type = na; 
    using tag = na; 
    using next = arg<5>; 
    template<typename U1 = na, typename U2 = na, typename U3 = na, typename U4 = na, typename U5 = na> 
    struct apply {
        using type = U4;
    };
}; using _4 = arg<4>;
template<> struct arg<5> {
    static constexpr int value = 5; 
    using type = na; 
    using tag = na; 
    using next = arg<6>; 
    template<typename U1 = na, typename U2 = na, typename U3 = na, typename U4 = na, typename U5 = na> 
    struct apply {
        using type = U5;
    };
}; using _5 = arg<5>;

template<int N,int T1>
struct arity<arg<T1>, N>
{
    constexpr static int value=5;
};

template<>
struct arg<-1>
{
	constexpr static int value = -1;
	using type = na;
	using tag = na;
	template<PP_DEFAULT_PARAMS_5(typename U, na)>
	struct apply
	{
		using type = U1;
	};
};
using _ = arg<-1>;

template< typename T >
struct is_placeholder: bool_<false>
{};

template< int N >
struct is_placeholder< arg<N> >: bool_<true>
{};