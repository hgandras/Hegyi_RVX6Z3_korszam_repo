#include <iostream>
#include <math.h>
#include "Deriv.h"

using namespace std;


float kozeppontos(float n,const float f,const float q,const float h,const float a,float delta){
    float res=0.00;
    float n_step=a/n;
    for(float i=n_step/2;i<a;i+=n_step){
        res+=sqrt(1+pow(hatod_deriv(i,f,q,h,a,delta),2))*n_step;
    }

    return res;
}

float trapez(float n,const float f,const float q,const float h,const float a,float delta){
    float res=0;
    float x_0=0;
    float n_step=a/n;
    for(float i=n_step;i<=a;i+=n_step){
        res+=2*sqrt(1+pow(hatod_deriv(i,f,q,h,a,delta),2))*n_step/2;
    }

    return res+sqrt(1+pow(hatod_deriv(x_0,f,q,h,a,delta),2))*n_step/2;
}

float harmad_simpson(float n,const float f,const float q,const float h,const float a,float delta){
    return (2*kozeppontos(n,f,q,h,a,delta)+trapez(n,f,q,h,a,delta))/3;
}