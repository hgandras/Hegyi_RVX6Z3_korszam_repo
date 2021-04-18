#include <iostream>
#include <math.h>
#include <vector>
#include "Butterfly.h"

using namespace std;

int main()
{
    
    Lorenz pillango1(10,28,8/3,1,0.001,0,1,0);
    Lorenz pillango2(10,28,8/3,1,0.001,1,1.1,1);
    pillango1.data_export("output1.txt");
    pillango1.Lyapunov(pillango2);


    return 0;
}