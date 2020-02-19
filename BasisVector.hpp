#include "Axis.hpp"
#include "Integral.hpp"

class BasisVector {
 public:
  using Length = Integral<uint64_t>;
 private:
  Axis axis;
  Length length;
 public:
  BasisVector() = default;
  BasisVector(Axis const& axis, Length const& length) : axis { axis }, length { length } { }
  void output_on(std::ostream& os) const {
    os << axis << ": " << length;
  }
  friend std::ostream& operator<<(std::ostream& os, BasisVector const& vec) {
    vec.output_on(os);
    return os;
  }
};
