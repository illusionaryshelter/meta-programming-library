#pragma once
#include "apply_fwd.h"
#include "wrapper/wrapper.h"
#include "processor/processor.h"
#include "type_traits/mpl_type_traits.h"
//-------------------------------------------


//-------------------------------------------
template<typename F, typename has_ = bool_<is_apply<F>> >
struct apply_wrap0:F::template apply<>
{};
//-------------------------------------------
template<typename F>
struct apply_wrap0<F,true_>:F::apply
{};
//-------------------------------------------
template<typename F, typename T1>struct apply_wrap1 : F :: template apply<T1>{};
template<typename F, typename T1, typename T2>struct apply_wrap2 : F :: template apply<T1, T2>{};
template<typename F, typename T1, typename T2, typename T3>struct apply_wrap3 : F :: template apply<T1, T2, T3>{};
template<typename F, typename T1, typename T2, typename T3, typename T4>struct apply_wrap4 : F :: template apply<T1, T2, T3, T4>{};
template<typename F, typename T1, typename T2, typename T3, typename T4, typename T5>struct apply_wrap5 : F :: template apply<T1, T2, T3, T4, T5>{};
