#include <iostream>
#include <typeinfo> 
using std::cout;
#define __MPL
#define __POP_RETURN
#include "mpl.h"
template <int N>
consteval int fibonacci() {
    if constexpr (N <= 1) {
        return N;
    }
    else {
        return fibonacci<N - 1>() + fibonacci<N - 2>();
    }
}
int main()
{
	using type = range_c<int,1,20>;
	using res=fold<type,int_<0>,plus<_,_>>::type;
    using res1=apply<plus<_,_>,int_<1>,int_<2>>::type;
    cout<< fibonacci<10>();
}
