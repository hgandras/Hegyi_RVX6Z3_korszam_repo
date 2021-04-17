#include <iostream>
#include "Integral.h"
#include <math.h>

using namespace std;


int main(){
    
    const float F=900;
    const float q=1.8;
    const float h=35;
    const float a=200;
    float delta;

    cout<<"Kérek egy delta hibatagot:"<<endl;
    cin >> delta;

    
    float deriv_2_max=0;
    float deriv_1=0;

    for(float i = a/200; i < 200; i+=a/200){
        cout<<hatod_deriv(i,F,q,h,a,delta)<<'\n';
    }
    cout<<kozeppontos(1000,F,q,h,a,delta)<<endl;

    cout<<trapez(1000,F,q,h,a,delta)<<endl;

    cout<<harmad_simpson(1000,F,q,h,a,delta);



        



    return 0;
}
