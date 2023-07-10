#pragma once
#include "miscellaneous/aux_type.h"
#include "processor/processor.h"
template<typename F,PP_DEFAULT_PARAMS_5(typename T,na)>
struct bind;

template<typename F>
struct bind0;
//
//#define BIND_FWD(i)\
//template<typename F,PP_CAT(PP_DEFAULT_PARAMS__,i)(typename T)>\
//struct PP_CAT(bind,i);

template<typename F, typename T1>struct bind1;
template<typename F, typename T1, typename T2>struct bind2;
template<typename F, typename T1, typename T2, typename T3>struct bind3;
template<typename F, typename T1, typename T2, typename T3, typename T4>struct bind4;
template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5>struct bind5;