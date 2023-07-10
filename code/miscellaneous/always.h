#pragma once
#include "bind/bind.h"
#include "miscellaneous/identity.h"
#include "composition/placeholder.h"
template<typename Value>
struct always
   :bind<identity<_1>,Value>
{};