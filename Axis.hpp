#pragma once

#include <iostream>

enum class Axes
{
  kX,
  kY,
  kZ
};

class Axis
{
 private:
  Axes axes;

 public:
  Axis() = default;
  Axis(Axes const& axes) : axes{axes} { }

  void print_on(std::ostream& os) const
  {
    switch (axes)
    {
      case Axes::kX:
        os << "X";
        break;
      case Axes::kY:
        os << "Y";
        break;
      case Axes::kZ:
        os << "Z";
        break;
      }
  }

  friend std::ostream& operator<<(std::ostream& os, Axis const& axes_obj)
  {
    axes_obj.print_on(os);
    return os;
  }
};
