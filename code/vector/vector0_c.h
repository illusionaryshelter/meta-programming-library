#pragma once
#include "wrapper/integral_c.h"
#include "vector0.h"
template<typename T>
struct vector0_c
	:vector0<>
{
	using type=vector0_c;
	using value_type=T;
};