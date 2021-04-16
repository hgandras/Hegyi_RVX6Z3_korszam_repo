#include <iostream>
#include "Deriv.h"
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

    


    for(float i = a/200; i < 200; i+=a/200){
        cout<<hatod_deriv(i,F,q,h,a,delta)<<'\n';
    }

    

        



    return 0;
}
