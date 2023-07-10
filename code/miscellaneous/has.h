#pragma once
#include "wrapper/wrapper.h"

//template<typename T,typename fallback_=false_>
//	struct has_apply
//	{
//		struct wknd
//		{
//			template<typename U>
//			static yes_tag test(type_wrapper<U> const volatile*,type_wrapper<typename U::apply>* =0);
//			static no_tag test(...);
//		};
//		using t_=type_wrapper<T>;
//		static constexpr bool value=
//		sizeof(wknd::test(static_cast<t_*>(0)))==sizeof(yes_tag);
//		using type=bool_<value>;
//	};
//
//
//template< typename T, typename fallback_ = true_ >
//    struct has_type
//    {
//        struct wknd
//        {
//            template< typename U >
//            static yes_tag test(
//                type_wrapper<U> const volatile*
//                , type_wrapper<typename U::type>* = 0
//            );
//
//            static no_tag test(...);
//        };
//
//        using t_=type_wrapper<T> ;
//        constexpr static bool value =
//            sizeof(wknd::test(static_cast<t_*>(0)))
//            == sizeof(yes_tag);
//        using type=bool_<value> ;
//    };
//
//    template< typename T, typename fallback_ = false_ >
//    struct has_tag
//    {
//        struct wknd
//        {
//            template< typename U >
//            static yes_tag test(
//                type_wrapper<U> const volatile*
//                , type_wrapper<typename U::tag>* = 0
//            );
//
//            static no_tag test(...);
//        };
//
//        using t_ = type_wrapper<T>;
//        constexpr static bool value =
//            sizeof(wknd::test(static_cast<t_*>(0)))
//                == sizeof(yes_tag);
//        using type = bool_<value>;
//    };