#include "Axis.hpp"
#include <array>

int main()
{
  std::array<Axis, 3> const values { Axes::kX,
                                     Axes::kY,
                                     Axes::kZ };
  for (auto&& value : values)
    std::cout << value << '\n';
}
