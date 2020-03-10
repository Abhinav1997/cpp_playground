// Given a string of digits, return the longest substring with alternating
// odd/even or even/odd digits. If two or more substrings have the same
// length, return the substring that occurs first.

#include <iostream>
#include <string>

// Type of digit(odd or even)
// Zero is considered even in this case
// Neither is the initial type before iteration has started
enum class Type {
  kNeither,
  kEven,
  kOdd
};

// Function to return the type of digit(odd or even)
Type type(const char digit_char) {
  const uint8_t digit { static_cast<uint8_t>(digit_char - '0') };
  return digit % 2 == 0 ? Type::kEven : Type::kOdd;
}

std::string longestSubstring(const std::string& digits) {
  size_t final_length {};
  size_t curr_length {};
  std::string longest_substr;
  std::string::const_iterator store_iter;
  Type prev_type { Type::kNeither };
  auto iter { digits.begin() };
  for (; iter != digits.end(); ++iter) {
    if (type(*iter) != prev_type) {
      // Increment length if the current digit type is different
      // to the previous digit type
      ++curr_length;
    } else {
      // If the current digit type is the same as the previous digit type and if
      // the length is greater than the length of the last recorded substring,
      // store the new iterator pointing to the current longest substring
      if (curr_length > final_length) {
        final_length = curr_length;
        store_iter = iter;
      }
      // Reset the length counter when the previous digit type
      // is the same as the current digit type
      curr_length = 1;
    }
    prev_type = type(*iter);
  }
  // Check for the length of the substring at the end of the digits string
  if (curr_length > final_length) {
    final_length = curr_length;
    store_iter = iter;
  }
  // Assign the longest found substring using the stored iterator
  longest_substr = std::string(store_iter - final_length, store_iter);
  return longest_substr;
}

int main() {
  std::cout << longestSubstring("111111") << '\n';
  std::cout << longestSubstring("111112325436351113434343434666") << '\n';
  std::cout << longestSubstring("111112325436351113434343434") << '\n';
  std::cout << longestSubstring("1234567890") << '\n';
  return 0;
}
