#include <math.h>
#include <iostream>
#include <string>

  double Trigo(double Num)
  {
  double a;
  a=sin(Num);
  return a;
  }

int main()
{
  double a;
  std::cin >> a;
  std::cout << Trigo(a);
}
