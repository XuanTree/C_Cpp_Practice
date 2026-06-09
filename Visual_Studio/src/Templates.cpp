#include "../include/Templates.h"

template <typename T1, typename T2>
inline const T1 SimpleCalculator<T1, T2>::getX() const {
  return x;
}

template <typename T1, typename T2>
inline const T2 SimpleCalculator<T1, T2>::getY() const {
  return y;
}

template <typename T1, typename T2>
void SimpleCalculator<T1, T2>::Plus() const {
  std::cout << x + y << std::endl;
}

template <typename T1, typename T2>
void SimpleCalculator<T1, T2>::Minus() const {
  std::cout << x - y << std::endl;
}

template <typename T1, typename T2>
void SimpleCalculator<T1, T2>::Multiply() const {
  std::cout << x * y << std::endl;
}

template <typename T1, typename T2>
void SimpleCalculator<T1, T2>::Devide() const {
  std::cout << x / y << std::endl;
}

template class SimpleCalculator<double, double>;
