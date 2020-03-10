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
  Type prev_type { Type::kNeither };
  auto iter { digits.begin() };
  for (; iter != digits.end(); ++iter) {
    if (type(*iter) != prev_type) {
      // Increment length if current digit type is different to previous type
      ++curr_length;
    } else {
      // If the type of the digit is same as previous type
      // And if the length is greater than length of last recorded substring
      // Change the longest substring to the current substring
      if (curr_length > final_length) {
        final_length = curr_length;
        longest_substr = std::string(iter - curr_length, iter);
      }
      // Reset length counter when previous digit type is same as current digit type
      curr_length = 1;
    }
    prev_type = type(*iter);
  }
  // Check for substring length at the end of the string
  if (curr_length > final_length)
    longest_substr = std::string(iter - curr_length, iter);
  return longest_substr;
}

int main() {
  std::cout << longestSubstring("0123254363511134343") << '\n';
  std::cout << longestSubstring("111112325436351113434343434666") << '\n';
  std::cout << longestSubstring("111112325436351113434343434") << '\n';
  std::cout << longestSubstring("1234567890") << '\n';
  return 0;
}
