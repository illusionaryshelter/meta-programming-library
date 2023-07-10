# P_MPL

> C++ Meta Programming Library

p_MPL is a simplified metaprogramming library based on boost/mpl. It utilizes modern C++ to simplify code and provides a foundation for beginners to learn metaprogramming or make improvements according to their needs. It has minimal coupling to the standard library and primarily supports fundamental metaprogramming behaviors. In the following section, I will provide a brief description and introduction to these behaviors.

## Features

### Compile time placeholder

```c++
#include "mpl.h"
using namespace ph;
using type=apply<plus<_,_>,int_<1>,int_<2>>::type;
```

### Compile operator

```c++
#include "mpl.h"
using type=deref<begin<vector<int,long>>::type>::type;
using type_2=bitand_<int_<2>,int_<6>>::type;
using type_3=assign<int_<2>,4>::type;
using type_4=modulus<int_<2>,int_<6>>::type;
```

### Compile Container and Iterator

```c++
#include "mpl.h"
using type=vector<int,long,double>;
using Iter=at<type,int_<2>>::type;
using type_2=vector_c<int,1,2,3,4>;
using type_3=range_c<int,1,9>;
```

### Compile algorithm

```c++
#include "mpl.h"
using type = range_c<int,1,20>;
auto res=fold<type,int_<0>,plus<_,_>>::type::value;
```

## Update Plan

### Version 1.0  (current version)

**Initial version, released in July 2023**

### Version 1.1

**Plan to add more containers and algorithm support(Determined)**

### Version 1.2

**Plan to incorporate reflection to optimize some behaviors(be pending)**

# Manual

## 1.algorithm

Currently, only three algorithms are supported

### fold

`template< typename Sequence , typename State , typename ForwardOp > `

`struct fold;`

Returns the result of the successive application of binary ForwardOp to the result of the previous ForwardOp invocation (State if it’s the first call) and every element of the sequence in the range [begin::type, end::type) in order

### iter_fold

`template< typename Sequence , typename State , typename ForwardOp > `

`struct iter_fold;`

Returns the result of the successive application of binary ForwardOp to the result of the previous ForwardOp invocation (State if it’s the first call) and each iterator in the range [begin::type, end::type) in order

### transform

`template< typename Seq , typename Op , typename In = unspecified > `

`struct transform;`

transform returns a transformed copy of the original sequence produced by applying an unary transformation Op to every element in the [begin::type, end::type) range.

## 2.apply

`template< typename F , typename A1 = unspecified ... , typename An = unspecified > `

`struct apply;`

Invokes a Metafunction Class or a Lambda Expression F with arguments A1,... An.

## 3.arithmetic

Provide operator element functions corresponding to runtime

## 4.bind

`template< typename F , typename A1 = unspecified ... , typename An = unspecified > `

`struct bind;`

bind is a higher-order primitive for Metafunction Class composition and argument binding.

## 5.composition

Provide placeholder and lambda support

## 6.inserter

Provide sequence inserter

## 7.intrinsic

Provides built-in metafunction support for sequences, corresponding to container operations at run time

## 8.iteration

Provide Iterator support

## 9.lambda

`template< typename X , typename Tag = unspecified >` 

`struct lambda;`

If X is a Placeholder Expression, transforms X into a corresponding Metafunction Class, otherwise X is returned unchanged

## 10.miscellaneous

Provide some miscellaneous meta functions

## 11.processor

Provide some macro support for simplifying code

## 12.range

range is a sorted Random Access Sequence of Integral Constants. It is inert and only exposes elements when used.

Its maximum parameter support is variable, and you can directly modify them in the source code to provide more support

## 13.type_traits

Provide support for type judgment

## 14.vector

vector is a variadic, random access, extensible sequence of types that supports constant-time insertion and removal of elements at both ends, and linear-time insertion and removal of elements in the middle.

Its maximum parameter support is variable, and you can directly modify them in the source code to provide more support

**I also provided a vector_ c,vector_c is an Integral Sequence Wrapper for vector.**

## 15.wrapper

Provide support for integer constants

An Integral Constant is a holder class for a compile-time value of an integral type. Every Integral Constant is also a nullary Metafunction, returning itself. An integral constant object is implicitly convertible to the corresponding run-time value of the wrapped integral type.