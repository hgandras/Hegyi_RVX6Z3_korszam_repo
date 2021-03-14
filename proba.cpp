#include <iostream>

using namespace std;

bool stop(double x, double y, double interv)
{
    return abs(x-y)>interv ?  true :false;

}

template<typename T,typename A,typename B,typename C>
double newton_iterator(A  f, B df, T start, T eps, C s)
{   
    T x0 = start;
    T x1 = x0-(f(x0)/df(x0));
    while(s(x0,x1,eps))
    {
        x0=x1;
        x1=x0-(f(x0)/df(x0));  
    }
    return x1;
}

int main()
{
    cout << newton_iterator([](double x){return x*x-612.0;}, [](double x){return 2.0*x;} , (double)100, 0.005, stop) << endl;
    cout << "Megállási paraméter lambda függvénnyel:" << newton_iterator([](double x){return x*x-612.0;}, [](double x){return 2.0*x;} , 100.0, 0.005, [](double x, double y, double interv){ return abs(x-y)>interv ?  true :false;}) << endl;
}