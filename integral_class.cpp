#include <assert.h>

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
  Integral(const U& value) : value { static_cast<T>(value) } { }
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

  void input_in(std::istream &is) {
    is >> value;
  }

  void output_on(std::ostream &os) const {
    os << value;
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


int main() {
  std::cout << "Begin test...\n";
  Integral<int> a { 6 };
  Integral<int> b { 2 };
  assert(a + b == 8);
  assert(a - b == 4);
  assert(a * b == 12);
  assert(a / b == 3);
  a += 2;
  assert(a == 8);
  a -= 2;
  assert(a == 6);
  a *= 2;
  assert(a == 12);
  a /= 2;
  assert(a == 6);
  b = 0;
  assert(b != 1);
  assert(!b == 1);
  assert(a && b == 0);
  assert(a || b == 1);
  Integral<char> c;
  std::cout << "Input value: ";
  std::cin >> c;
  std::cout << "Output value: " << c << '\n';
  std::cout << "Test successful.\n";
}
