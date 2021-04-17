#include <iostream>
#include "Integral.h"
#include <math.h>
#include <fstream>

using namespace std;


int main(){
    
    const float F=900;
    const float q=1.8;
    const float h=35;
    const float a=200;
    float delta;
    float perc;

    cout<<"Kérek egy derivált delta hibatagot:";
    cin >> delta;
    cout<<"Kérek egy integrál százalékos hibát (0 és 1 között):";
    cin>>perc;

    
    float deriv_2_max=0;
    float deriv_4_max=0;
    float deriv_1=0;
    float deriv_2=0;
    float deriv_3=0;
    float deriv_4=0;

    for(float i = a/10000; i < 200; i+=a/10000){
        deriv_1=hatod_deriv(i,F,q,h,a,delta);
        deriv_2=hatod_deriv(deriv_1,F,q,h,a,delta);
        deriv_3=hatod_deriv(deriv_2,F,q,h,a,delta);
        deriv_4=hatod_deriv(deriv_3,F,q,h,a,delta);
        if (abs(deriv_2)>deriv_2_max){
            deriv_2_max=abs(deriv_2);
        }
        if (abs(deriv_4)>deriv_4_max){
            deriv_4_max=abs(deriv_4);
        }
    }

    float n_kozep=sqrt(deriv_2_max*(a*a*a)/(24*perc));
    float n_trapez=sqrt(deriv_2_max*(a*a*a)/(12*perc));
    //float n_simp=pow(a*a*a*a*a*deriv_4_max/(2880*perc),1/4);
    float n_simp_2=(2*n_kozep+n_trapez)/3;

    float len_kozeppontos=kozeppontos(n_kozep,F,q,h,a,delta);
    float len_trapez=trapez(n_trapez,F,q,h,a,delta);
    float len_simp=harmad_simpson(n_simp_2,F,q,h,a,delta);

    ofstream f;
    f.open("output.txt");
    f<<len_kozeppontos<<','<<len_trapez<<','<<len_simp<<endl;
    f<<"Megjegyzés: 4. deriváltnál nagyon kicsi érték jött ki, ezért a harmad Simpson módszer esetében n-re 1 jött ki,\n"<<"amire nagyon nem volt pontos az eredmény. Emiatt ahhoz az n-et a (2*középpontos+trapéz)/3 szerint számoltam.";
    f.close();




        



    return 0;
}
