#include <iostream>
#include <string>

template <class T>
class table{
private:
  int ROWS;
  int COLS;
  T **arr;
public:
  table(int ROWS_, int COLS_) : ROWS{ROWS_}, COLS{COLS_} {
    arr = new T*[ROWS];
    for(int i{}; i < COLS; ++i){
      arr[i] = new T[COLS];
    }
  }

  class proxy{
  private:
    T* pro_arr;
  public:
    proxy(T* arr_) : pro_arr{arr_} {}
    T& operator[](const int index){
      return pro_arr[index];
    }
  };
  proxy operator[](const int index){
    return proxy(arr[index]);
  }

  proxy operator[](const int index) const{
    return proxy(arr[index]);
  }

  table operator=(const table &other){
    ROWS = other.ROWS;
    COLS = other.COLS;
    for(int i{}; i < ROWS; ++i){
      for(int j{}; j < COLS; ++j){
        arr[i][j] = other[i][j];
      }
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream &stream, T a){
    stream << a;
    return stream;
  }

  void Size(){
    std::cout << "SIZE: " + std::to_string(ROWS) + "x" + std::to_string(COLS);
  }
  
  ~table(){
    for(int i{}; i < ROWS; ++i){
      delete[] arr[i];
    }
    delete[] arr;
  }
};

int main(){
  auto test = table<int>(2, 3);
  test[0][0] = 4;
  std::cout << test[0][0] << std::endl;
  test.Size();
  return EXIT_SUCCESS;
}