#pragma once
#include "iterator_tag.h"
#include "miscellaneous/aux_type.h"
#include "composition/template_arity.h"
#include "lambda/lambda.h"
#include "composition/arity.h"
#define UNROLLING 4

//！！！！！！！！！！！！！！！！！！！！！！！！！！
 template<class Iterator,class Type=na>
 struct deref
 {
    using type= typename Iterator::type;
 };
 //！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<typename Iterator=na>
struct iterator_category
{
    using type= typename Iterator::catagory;
};
//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
template<class Iterator = na>
struct next {
    using type = typename Iterator::next;
    using arity = int_<1>;
    using arg0 = Iterator;
    struct rebind
    {
        template<typename U0>
        struct apply :next<U0> {};
    };
};
template<>
struct next<na>
{
    template<typename T>struct apply:next<T>{};
};
