#include <iostream>
#include "vekt2.h"

using namespace std;

# define M_PIl          3.141592653589793238462643383279502884L /* pi */


int main() {
   vekt2d <float> v={1,2};
   vekt2d <float> u={3,4};

   vekt2d <float> vekt1{0,0};
   vekt2d <float> vekt2{0,0};

   cout<<"Vektor 1:"<<endl;
   cin>>vekt1;
   cout<<"Vektor 2:"<<endl;
   cin>>vekt2;

   cout<<"A vektorok osszege:"<<vekt1+vekt2<<endl;
   cout<<"A két vektor különbsége:"<<vekt1-vekt2<<endl;
   cout<<"Első vektor szorozva skalárral:"<<vekt1*4<<endl;
   cout<<"Második vektor leosztva skalárral:"<<vekt2/4<<endl;
   cout<<"Első vektor hossza:"<<length(vekt1)<<endl;
   cout<<"Első vektor hossznégyzete:"<<sqlength(vekt1)<<endl;
   cout<<"Skalárszorzatuk:"<<dot(vekt1,vekt2)<<endl;


   cout<<"Most a structon belüli metódusokat írom ki:"<<endl;

   cout<<"Az első vektorhoz hozzáadom az másodikat:"<<(vekt1+=vekt2)<<endl;
   cout<<"A módosított elsőből kivonom a másodikat:"<<(vekt1-=vekt2)<<endl;
   cout<<"Másodikat skalárral szorzom:"<<(vekt2*=3.5)<<endl;
   cout<<"Módosított másodikat leosztom ugyanazzal a skalárral:"<<(vekt2/=3.5)<<endl;
   cout<<"Elsőt lenormálom:"<<vekt1.normalize()<<endl;

   float angle;

   cout<<"Adj meg egy szöget radiánban:"<<endl;
   cin>>angle;
   cout<<"Másodikat elforgatom a megadott szöggel"<<vekt2.rotate(angle)<<endl;

   return 0;


}