//Caida libre de un paracaidiste
//m=68.1 kg t=10 s  g=9.81m/s^2 v= 40m/s
#include <cmath>
#include <iostream>
using fun=double(double);
double Velff(double c);
const double m=68.1,t=10,g=9.81,v=40;
double bisectio(double u, double l, fun function();
int main ()
{
  double c=1;
  while (c<20)
    {
      std::cout<<c<<"\t" << Velff(c) << std::endl ;
      c = c+1;
    }
}

double Velff(double c)
{
  double vel;
  vel=(m*g/c)*(1-std::exp(-c*t/m))-40;
}
