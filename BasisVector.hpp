#include "Axis.hpp"
#include "Integral.hpp"

#include <array>

template <typename T, typename Enable = void>
class BasisVector;

template <typename T>
class BasisVector<T, typename std::enable_if_t<std::is_integral_v<T>>> {
 private:
  std::array<Axis, 3> axes { Axes::kX, Axes::kY, Axes::kZ };
  std::array<Integral<T>, 3> dimensions;
 public:
  BasisVector() = default;
  BasisVector(Integral<T> const& x, Integral<T> const& y, Integral<T> const& z) : dimensions { x, y, z  } { }
  void output_on(std::ostream& os) const {
    for (size_t index { }; index < axes.size(); ++index)
      os << axes.at(index) << ": " << dimensions.at(index) << '\n';
  }
  friend std::ostream& operator<<(std::ostream& os, BasisVector const& vec) {
    vec.output_on(os);
    return os;
  }
};
