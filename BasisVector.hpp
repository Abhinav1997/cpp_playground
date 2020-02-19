#include <iostream>
#include <type_traits>

template <typename T, typename Enable = void>
class BasisVector;

template <typename T>
class BasisVector<T, typename std::enable_if_t<std::is_integral_v<T>>> {
 private:
  T x;
  T y;
  T z;
 public:
  BasisVector() = default;
  BasisVector(T const& x, T const& y, T const& z) : x { x }, y { y }, z { z } { }
  void output_on(std::ostream& os) const {
    os << "X: " << x << ", Y: " << y << ", Z: " << z;
  }
  friend std::ostream& operator<<(std::ostream& os, BasisVector<T> const& vec) {
    vec.output_on(os);
    return os;
  }
};
