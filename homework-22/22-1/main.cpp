#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
T square(T x){
  return x * x;
}

template<class T>
void square(std::vector<T> &vec){
  std::transform(vec.begin(), vec.end(), vec.begin(), [](T a){ return a * a;});
}

int main(){
  std::cout << square(4) << std::endl;
  std::vector<int> vec = {-1, 4, 8};
  square(vec);
  for(auto i : vec){
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
