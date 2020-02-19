#include <array>
#include <iostream>

enum class Elements {
  kValueOne,
  kValueTwo,
  kValueThree
};

class Element {
private:
  Elements element;
public:
  Element() = default;
  Element(const Elements& element) : element { element } {};

  void print_on(std::ostream& os) const {
    switch (element) {
    case Elements::kValueOne:
      os << "kValueOne";
      break;
    case Elements::kValueTwo:
      os << "kValueTwo";
      break;
    case Elements::kValueThree:
      os << "kValueThree";
      break;
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const Element& element_obj) {
    element_obj.print_on(os);
    return os;
  }
};

int main() {
  const std::array<Element, 3> values { Elements::kValueOne,
                                        Elements::kValueTwo,
                                        Elements::kValueThree };
  for (const auto& value : values)
    std::cout << value << '\n';
}
