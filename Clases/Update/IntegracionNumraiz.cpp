//programa para integracion numerica
#include <iostream>
#include <cmath>

using func = double (double);

double TrapecioRichardson(const double a, const double b, const int n, func Funtion);
double Trapecio(const double a, const double b, const int n, func Funtion);
double Simpson(const double a, const double b, const int n, func Funtion);
double function(double x);
int main ()
{
  const int N = 20;

  std::cout << "Metodo trapecio (n=20):" << Trapecio(-1, 1, N, function) << std::endl ;
  std::cout << "Metodo trapecio (n=40):" << Trapecio(-1, 1, N*2, function) << std::endl ;
  std::cout << "Metodo trapecio richardson (n=20):" << TrapecioRichardson(-1, 1, N, function) << std::endl ;   
  std::cout << "Metodo simpson (n=20):" << Simpson(-1, 1, N, function) << std::endl ;
}

double Trapecio(const double a, const double b, const int n, func Funtion)
{
  double h = (a-b)/n;

  double alpha = (Funtion(a)+Funtion(b))/2;
  double Sum = 0;
  int i =1;
  while(i<(n-1))
    
    {
      Sum = Sum + Funtion (h*i+a);
      i=i+1;
    }
  return (Sum+alpha)*h;
}
double TrapecioRichardson(const double a, const double b, const int n, func Funtion)
{
  double result = (4*Trapecio(a,b,2*n,Funtion)-Trapecio(a,b,n,Funtion))/3;
  return result;
}		
double Simpson(const double a, const double b, const int n, func Funtion)
{
  double h =(b-a)/n ;
  double alpha = Funtion(a)+Funtion(b)  ;
  double suma = 0;
  double sumb = 0;
  double x;
  double result;
  int i =1;
  while(i<=(n/2-1))
    {
      x=a+(i*h*2);
      suma += function(x);
      i=i+1;
    }
  i=1;
  while(i<=(n/2))
    {
      x= a+(2*i-1)*h;
      sumb += function(x);
      i=i+1;
    }
  result = (2*suma+4*sumb+alpha)*h/3;
  return result;
}
double function(double x)
 {
   return (1.0-pow(x,2.0))*(-1.0/2.0);
 }
