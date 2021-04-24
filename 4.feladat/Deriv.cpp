#include <iostream>
#include <math.h>
#include <vector>


using namespace std;


template<typename T>
auto func(T y){
    return 1+pow(y,2);
}

template<typename T>
vector analytic(){

    return ;
}


template<typename T>
vector<T> Newton(vector<T> y,T (*f)(T),T y0 ,T t0,T full_t,T t_step){
    int i=1;
    y.push_back(y0);
    for (int i=1;i<=(full_t-t0)/t_step;i+=1){
        y.push_back(y[i-1]+f(y[i])*t_step);
    }
    return y;
}

template<typename T>
vector<T> RK4(vector<T> y,T (*f)(T),T y0,T t0,T full_t,T t_step){
    double k1,k2,k3,k4;
    y.push_back(y0);
    for(int i=1;i<=(full_t-t0)/t_step;i+=1)


    return y;
}



int main(){
    
    double t0,t_full,t_step,y0;
    vector<double> outp;

    cout<<"t0: ";
    cin>>t0;
    cout<<"y0: ";
    cin>>y0;
    cout<<"t_step: ";
    cin>>t_step;
    cout<<"t_full: ";
    cin>>t_full;
    
    vector<double> res;

    vector<double> results=Newton(res,func,y0,t0,t_full,t_step);
    for(int i=0;i<results.size();i++)
        cout<<results[i]<<endl;



    return 0;
}