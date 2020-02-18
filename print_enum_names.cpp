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
  const Element value_one { Elements::kValueOne };
  const Element value_two { Elements::kValueTwo };
  const Element value_three { Elements::kValueThree };
  std::cout << value_one << ' ' << value_two << ' ' << value_three << '\n';
}
