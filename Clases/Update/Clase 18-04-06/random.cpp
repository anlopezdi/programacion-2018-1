
// http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
#include <random>
#include <iostream>

int main()
{
  int seed = 0;
  std::mt19937 gen(seed);
   std::normal_distribution<> dis(1.5,0.3);
   for (int n = 0; n < 100000; ++n) {
     //Use dis to transform the random unsigned int generated by gen into a double in [1, 2)
     std::cout << dis(gen) << '\n'; //Each call to dis(gen) generates a new random double
   }
   std::cout << '\n';
 }