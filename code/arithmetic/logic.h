#pragma once
#include "type_traits/mpl_type_traits.h"
#include "miscellaneous/if_.h"

template<typename ...Arg>
struct or_ :false_type {};
template<typename T1>
struct or_<T1> :T1 {};
template<typename T1, typename ...Tn>
struct or_<T1, Tn...> :if_<T1, T1, or_<Tn...>>::type {};


template<typename ...Arg>
struct and_ :true_type {};
template<typename T1>
struct and_<T1> :T1 {};
template<typename T1, typename ...Tn>
struct and_<T1, Tn...> :if_<T1, and_<Tn...>, T1>::type {};


template<typename Arg>
struct not_ : integral_constant<bool, !Arg::value> {};