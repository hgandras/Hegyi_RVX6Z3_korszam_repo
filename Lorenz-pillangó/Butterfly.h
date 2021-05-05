#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;


class Lorenz{

    

    public:

    double t;

    vector<vector<double>> vekt;

    Lorenz(const double sigma,const double rho,const double beta,const double full_t,double delta_t,double start_x,double start_y,double start_z){

        t=delta_t;

        vekt.resize((int)full_t/delta_t);

        double x=start_x;
        double y=start_y;
        double z=start_z;
        double dx=0,dy=0,dz=0;
        for (int i=0;i<=(int)full_t/delta_t;i+=1){
            dx+=sigma*(y-x)*delta_t;
            dy+=(x*(rho-z)-y)*delta_t;
            dz+=(x*y-beta*z)*delta_t;
            x=dx;
            y=dy;
            z=dz;
            vekt[i].push_back(x);
            vekt[i].push_back(y);
            vekt[i].push_back(z);
        }

    }

    void data_export(string file_name){

        ofstream f(file_name);
        for (int i=0;i<vekt.size();i++){
            f<<vekt[i][0]<<","<<vekt[i][1]<<","<<vekt[i][2]<<endl;   
        }
        f.close();

        return;
    }

    vector<double> Lyapunov(Lorenz params2){

        vector<double> exponents;

        if (vekt.size()!=params2.vekt.size())
            cout<<"A két bemenő időskála hossza nem egyezik meg."<<endl;
        if (vekt.size()==params2.vekt.size()){
            double t_current=0;
            double delta_null=sqrt(pow(vekt[0][0]-params2.vekt[0][0],2)+pow(vekt[0][1]-params2.vekt[0][1],2)+pow(vekt[0][2]-params2.vekt[0][2],2));
            for (int i=1;i<vekt.size();i++){
                exponents.push_back(log((sqrt(pow(vekt[i][0]-params2.vekt[i][0],2)+pow(vekt[i][1]-params2.vekt[i][1],2)+pow(vekt[i][2]-params2.vekt[i][2],2)))/delta_null)/t_current);
                t_current+=t;
            }
        } 
        return  exponents;
          
    }



};


