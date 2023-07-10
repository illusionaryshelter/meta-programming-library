#pragma once
#include "wrapper/integral_c.h"
#include "miscellaneous/aux_type.h"
#include "miscellaneous/tag.h"
template<typename Obj=na,typename Tag=void_, Obj::value_type Value=0>
struct assign_impl;


template<typename Obj,Obj::value_type Value>
struct assign_impl<Obj,integral_c_tag,Value>
   :integral_c<typename Obj::value_type,Value>
{};

template<typename Obj,Obj::value_type Value>
struct assign
   :assign_impl<Obj,typename tag<Obj>::type,Value>
{};