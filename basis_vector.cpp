#include "BasisVector.hpp"

int main() {
  BasisVector<int> bv {1, 4, 7};
  std::cout << "Vector dimensions: \n";
  std::cout << bv;
}
