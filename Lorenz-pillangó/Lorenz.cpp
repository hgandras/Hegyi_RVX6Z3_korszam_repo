#include <iostream>
#include <math.h>
#include <vector>
#include "Butterfly.h"

using namespace std;

int main()
{
    
    Lorenz pillango1(10,28,8/3,100,0.005,0,1,0);
    Lorenz pillango2(10,28,8/3,100,0.005,0.0001,0.9999,0.0001);
    Lorenz pillango3(10,1,8/3,100,0.005,0,1,0);
    pillango1.data_export("output1.txt");
    pillango2.data_export("output2.txt");
    pillango3.data_export("output_ro1.txt");
    vector<double> res=pillango1.Lyapunov(pillango2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    


    return 0;
}