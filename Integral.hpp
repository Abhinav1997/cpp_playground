#include <iostream>

template <typename T, typename Enable = void>
class Integral;

template <typename T>
class Integral<T, typename std::enable_if_t<std::is_integral_v<T>>> {
 private:
  T value;

 public:
  Integral() = default;

  template <typename U>
  Integral(U const& value) : value{static_cast<T const&>(value)} { }

  Integral operator*(const Integral& rhs) const {
    return value * rhs.value;
  }

  Integral operator+(const Integral& rhs) const {
    return value + rhs.value;
  }

  Integral operator-(const Integral& rhs) const {
    return value - rhs.value;
  }

  Integral operator/(const Integral& rhs) const {
    return value / rhs.value;
  }

  Integral& operator*=(const Integral& rhs) {
    this->value *= rhs.value;
    return *this;
  }

  Integral& operator+=(const Integral& rhs) {
    this->value += rhs.value;
    return *this;
  }

  Integral& operator-=(const Integral& rhs) {
    this->value -= rhs.value;
    return *this;
  }

  Integral& operator/=(const Integral& rhs) {
    this->value /= rhs.value;
    return *this;
  }

  void input_in(std::istream& is) {
    long long val;
    is >> val;
    value = val;
  }

  void output_on(std::ostream& os) const {
    os << (long long)value;
  }

  friend std::istream& operator>>(std::istream& is, Integral& rhs) {
    rhs.input_in(is);
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Integral<T>& rhs) {
    rhs.output_on(os);
    return os;
  }

  friend bool operator!(const Integral& rhs) {
    return !rhs.value;
  }

  friend bool operator&&(const Integral& lhs, const Integral& rhs) {
    return (lhs.value && rhs.value);
  }

  friend bool operator||(const Integral& lhs, const Integral& rhs) {
    return (lhs.value || rhs.value);
  }

  friend bool operator==(const Integral& lhs, const Integral& rhs) {
    return lhs.value == rhs.value;
  }

  friend bool operator!=(const Integral& lhs, const Integral& rhs) {
    return lhs.value != rhs.value;
  }
};
