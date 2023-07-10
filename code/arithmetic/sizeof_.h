#pragma once
#include "wrapper/wrapper.h"
template<typename P=na>
struct sizeof_ 
   :size_t_<sizeof(P)>
{};