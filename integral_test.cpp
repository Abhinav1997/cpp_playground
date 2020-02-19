#include "Integral.hpp"

#include <cassert>

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

  Integral<uint32_t> c;
  std::cout << "Input value: ";
  std::cin >> c;
  std::cout << "Output value: " << c << '\n';
  std::cout << "Test successful.\n";
}
