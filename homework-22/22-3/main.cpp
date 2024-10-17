#include <iostream>
#include <vector>

template <class T>
class functor{
private:
  T sum;
  unsigned int count;
public:
 functor() : sum{0}, count{0} {}
  void operator()(const std::vector<T> &vec){
    for(int i{}; i < vec.size(); ++i){
      if(vec[i] % 3 == 0){
        sum += vec[i];
        ++count;
      }
    }
  }
  T get_sum(){
    return sum;
  }
  int get_count(){
    return count;
  }
  ~functor(){
    std::cout << "get_sum() = " << get_sum() << std::endl << "get_count() = " << get_count() << std::endl;
  }
};

int main(){
  std::vector<int> v{4, 1, 3, 6, 25, 54};
  functor<int> f;
  f(v);
  return EXIT_SUCCESS;
}