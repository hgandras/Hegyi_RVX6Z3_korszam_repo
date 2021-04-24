#include <iostream>
#include <math.h>
#include <vector>


using namespace std;


template<typename T>
auto func(T y){
    return 1+pow(y,2);
}

template<typename T>
vector<T> analytic(vector<T> y ,T t0,T full_t,T t_step){
    for (double i=t0;i<=full_t;i+=t_step){
        y.push_back(atan(i));
    }

    return y;
}


template<typename T>
vector<T> Newton(vector<T> y,T (*f)(T),T y0 ,T t0,T full_t,T t_step){
    y.push_back(y0);
    for (int i=1;i<=(full_t-t0)/t_step;i++){
        y.push_back(y[i-1]+f(y[i-1])*t_step);
    }
    return y;
}

template<typename T>
vector<T> RK4(vector<T> y,T (*f)(T),T y0,T t0,T full_t,T t_step){
    double k1,k2,k3,k4;
    y.push_back(y0);
    for(int i=1;i<=(full_t-t0)/t_step;i++){
        k1=f(y[i-1]);
        k2=f(y[i-1]+t_step*k1/2);
        k3=f(y[i-1]+t_step*k2/2);
        k4=f(y[i-1]+t_step*k3);
        y.push_back(y[i-1]+t_step*(k1+2*k2+2*k3+k4)/6);
        
    }


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

    vector<double> results_N=Newton(outp,func,y0,t0,t_full,t_step);
    vector<double> results_RK=RK4(outp,func,y0,t0,t_full,t_step);
    vector<double> results_analytic=analytic(outp,t0,t_full,t_step);
    for(int i=0;i<results_N.size();i++)
        cout<<results_N[i]<<','<<results_RK[i]<<','<<results_analytic[i]<<endl;




    return 0;
}