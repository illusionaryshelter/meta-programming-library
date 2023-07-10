#pragma once
#include "miscellaneous/aux_type.h"
#include "composition/template_arity.h"
#include "wrapper/wrapper.h"
template<typename T=na,typename Tag=void_,typename Arity=int_<template_arity<T>::value>>
struct lambda;