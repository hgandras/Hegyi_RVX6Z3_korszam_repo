#include <iostream>
#include <math.h>

using namespace std;

template<typename T>
auto func_kotel(T x,const T f,const T q,const T h,const T a){

    return (f/q)*(cosh(q*x/f)-cosh(q*a/(2*f)))+h;
}

template<typename T>
auto D(T x,const T f,const T q,const T h,const T a,T delta){

    return (func_kotel(x+delta,f,q,h,a)-func_kotel(x-delta,f,q,h,a))/(2*delta);
}

template<typename T>
auto S(T x,const T f,const T q,const T h,const T a,T delta){

    return (4*D(x,f,q,h,a,delta)-D(x,f,q,h,a,2*delta))/3;
}



template<typename T>
float hatod_deriv(T x,const T f,const T q,const T h,const T a,T delta){

    return (16*S(x,f,q,h,a,delta)-S(x,f,q,h,a,2*delta))/15;
}