#include <iostream>

template <class T>
void f(T &i) {
  std::cout << 1 << std::endl;
}

template <>
void f(const int &i) {
  std::cout << 2 << std::endl;
}

int main() {
  int i = 42;
  f(i);
}
