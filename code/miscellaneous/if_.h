#pragma once

template<bool C, typename T1, typename T2>
struct if_c { using type = T2; };
template<typename T1, typename T2>
struct if_c<true, T1, T2> { using type = T1; };
template<typename C, typename T1, typename T2>
struct if_ :if_c<C::value, T1, T2> {};
template<typename C, typename True, typename False>
struct eval_if :if_<C, True, False>::type {};
