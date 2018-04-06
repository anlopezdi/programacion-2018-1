//programa para calcular reices de un paracaidista callendo
//Caida libre de un paracaidiste
//m=68.1 kg t=10 s  g=9.81m/s^2 v= 40m/s
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using fun= double (double);
const double m=68.1 , t=10.0 , g=9.81, v=40.0;
//funciones
double velf(double c);
double veli(double c);
double veldev(double c);
double Metodografico(double inf, double max, fun function, std::string name);
double Metodobiseccion(double inf, double max, fun function, std::string name, int nmax);
double Metodofalsi (double inf, double max, fun function, std::string name, int nmax);
double Metodositeracion(fun functiona,fun functionb , double in, std::string name, int nmax);
double Metodonewton(fun function, fun functiondev,double ini, std::string name, int nmax);
int main()
{
Metodografico(1.0,20.0,velf,"Metodografico.txt");
Metodobiseccion(1.0,20.0,velf,"Metodobiseccion.txt",100);
Metodofalsi(1.0,20.0,velf,"Metodofalsi.txt",100);
Metodositeracion(velf,veli,20.0,"Metodositeracion",100);
Metodonewton(velf,veldev,20.0,"Metodonewton",100);
return 0;
}

//function es la funcion a sacar la raiz
//funciondev es la derivada de la funcion function
double Metodonewton(fun function, fun functiondev,double ini,std::string name, int nmax)
{
  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  double ii=1, x=ini;
  while (ii<=nmax && function(x)!=0)
  {
    x=x-(function(x)/functiondev(x));
    ii++;
    fout<<ii<<"\t"<<x<<"\t"<<function(x)<<"\n";
  }
  fout<<x;
  std::cout<<x;
  return(x);
}
//funtiona es la funcion f(x)=algo
//funtionb es la funcion x+1=x
double Metodositeracion(fun functiona,fun functionb ,double in, std::string name, int nmax)
{
  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  double ii=1,i=nmax,x=in ;
  while (ii<=i && functiona(x)!=0)
  {
    x=functionb(x);
    ii++;
    fout<<ii<<"\t"<<x<<functiona(x)<<"\n";
  }
  fout<<x;
  std::cout<<x;
  return(x);
}
double Metodografico(double inf, double max, fun function,std::string name)
{
  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  double i=inf;
  while (i<=max)
  {
    fout << i << "\t" << function(i) <<"\n";
    i++;
  }
}
double Metodofalsi (double inf, double max, fun function,std::string name, int nmax)
{
  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  double i=inf,m=max, r=function(i)*function(m), ii=0;
  double xr= m-(function(m)*(i-m)/(function(i)-function(m)));
  while(r!=0 && ii<nmax)
  {
    if(r<0)
    {
      m=xr;
    }
    else
    {
      i=xr;
    }
    fout << m << "\t" << i << "\n";
    ii++;
  }
  fout<< xr <<"\n";
  std::cout<<xr;
  return (xr);
}
double Metodobiseccion(double inf, double max, fun function,std::string name, int nmax)
{
  std::ofstream fout(name);
  fout.precision(16); fout.setf(std::ios::scientific);
  double i=inf,m=max, r=function(i)*function(m), ii=0;
  while (r!=0 && ii<nmax)
  {
    fout << m << "\t" << i << "\n";
    if(r>0)
    {
      m=(i+m)/2.0;
    }
    else
    {
      i=(i+m)/2.0;
    }
    ii++;
  }
  fout<<((i+m)/2.0)<<"\n" ;
  std::cout<<((i+m)/2.0);
  return ((i+m)/2.0);
}
double veli(double c)
{
  double vel;
  vel=log(-(v*c/m*g-1))*m/t;
  return vel;
}
double velf(double c)
{
  double vel;
  vel=(m*g/c)*(1-std::exp(-c*t/m))-v;
  return vel;
}
double veldev(double c)
{
  double vel;
  vel=g/pow(c,2)*exp(-c*t/m)*(-m*exp(c*t/m)+m+t*c);
  return vel;
}
