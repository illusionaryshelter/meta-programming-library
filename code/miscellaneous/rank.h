#pragma once
#include "wrapper/integral_c.h"
#include "if_.h"
#include "wrapper/wrapper.h"
template<typename T>struct integral_rank;
template<> struct integral_rank<bool> : int_<1> {};
template<> struct integral_rank<signed char> : int_<2> {};
template<> struct integral_rank<char> : int_<3> {};
template<> struct integral_rank<unsigned char> : int_<4> {};
template<> struct integral_rank<short> : int_<6> {};
template<> struct integral_rank<unsigned short> : int_<7> {};
template<> struct integral_rank<int> : int_<8> {};
template<> struct integral_rank<unsigned int> : int_<9> {};
template<> struct integral_rank<long> : int_<10> {};
template<> struct integral_rank<unsigned long> : int_<11> {};
template<> struct integral_rank<long long> : int_<12> {};
template<> struct integral_rank<unsigned long long> : int_<13> {};
template<typename T1, typename T2>
struct largest_int 
   :if_c<integral_rank<T1>::value >= integral_rank<T2>::value, T1, T2>
{};