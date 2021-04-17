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
        deriv_1=hatod_deriv(i,F,q,h,a,delta);
        cout<<deriv_1<<'\n';
        if (abs(hatod_deriv(deriv_1,F,q,h,a,delta))>deriv_2_max){
            deriv_2_max=hatod_deriv(deriv_1,F,q,h,a,delta);
        }
    }

    float n_kozep=sqrt(deriv_2_max*(a*a*a)/(24*0.01));
    float n_trapez=sqrt(deriv_2_max*(a*a*a)/(12*0.01));

    cout<<kozeppontos(n_kozep,F,q,h,a,delta)<<endl;

    cout<<trapez(n_trapez,F,q,h,a,delta)<<endl;

    cout<<harmad_simpson(1000,F,q,h,a,delta);



        



    return 0;
}
