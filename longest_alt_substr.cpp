// Given a string of digits, return the longest substring with alternating
// odd/even or even/odd digits. If two or more substrings have the same
// length, return the substring that occurs first.

#include <iostream>
#include <string>

// Improved solution from:
// https://reddit.com/r/cpp_questions/comments/fg8enw/longest_alternating_substring_code_challenge_how/fk3ta6g/
std::string longestSubstring(const std::string& digits) {
  size_t final_length {};
  size_t curr_length { 1 };
  size_t last_index { digits.size() };
  size_t store_index {};

  auto different_type {
                       [](int8_t digit) -> bool { return digit & 1; }
  };
  auto update_store_index {
                           [&final_length, &store_index, &curr_length](size_t index) {
                              if (curr_length > final_length) {
                                final_length = curr_length;
                                store_index = index;
                              }
                              // Reset the length counter when the previous
                              // digit type is the same as the current one
                              curr_length = 1;
                            }
  };

  for (size_t index { 1 }; index < last_index; ++index) {
    // Increment length if the current digit type is different
    // to the previous digit type
    // If the current digit type is the same as the previous digit type and if
    // the length is greater than the length of the last recorded substring,
    // store the new iterator pointing to the current longest substring
    if (different_type(digits.at(index) - digits.at(index - 1)))
      ++curr_length;
    else
      update_store_index(index);
  }
  // Check for the length of the substring at the end of the digits string
  update_store_index(last_index);
  // Return the longest found substring using the stored iterator
  return digits.substr(store_index - final_length, final_length);
}

int main() {
  std::cout << longestSubstring("111111") << '\n';
  std::cout << longestSubstring("111112325436351113434343434666") << '\n';
  std::cout << longestSubstring("111112325436351113434343434") << '\n';
  std::cout << longestSubstring("1234567890") << '\n';
  return 0;
}
