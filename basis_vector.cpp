#include "BasisVector.hpp"

#include <array>

int main() {
  std::array<BasisVector, 3> dims { BasisVector{Axes::kX, 1},
                                    BasisVector{Axes::kY, 4},
                                    BasisVector{Axes::kZ, 7} };
  std::cout << "Vector dimensions: \n";
  for (auto const& dim : dims)
    std::cout << dim << '\n';
}
