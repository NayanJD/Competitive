// https://leetcode.com/problems/decode-ways/description/
//
// 91. Decode Ways
//
// A message containing letters from A-Z can be encoded into numbers using the
// following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back
// into letters using the reverse of the mapping above (there may be multiple
// ways). For example, "11106" can be mapped into:
//
// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
// into 'F' since "6" is different from "06".
//
// Given a string s containing only digits, return the number of ways to decode
// it.
//
// The test cases are generated so that the answer fits in a 32-bit integer.
//
//
//
// Example 1:
//
// Input: s = "12"
// Output: 2
// Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
// Example 2:
//
// Input: s = "226"
// Output: 3
// Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2
// 2 6). Example 3:
//
// Input: s = "06"
// Output: 0
// Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is
// different from "06").
//
//
// Constraints:
//
// 1 <= s.length <= 100
// s contains only digits and may contain leading zero(s).

#include <stdio.h>
#include <string>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

class Solution {
public:
  int numDecodings(string s) {

    if (s.at(0) == '0') {
      return 0;
    }

    int prevDecodings{1}, prevPrevDecodings{1}, currentDecodings{0},
        currentNumber;

    for (int i = 1; i < s.size(); i++) {
      currentNumber = stoi(s.substr(i, 1));

      if (currentNumber != 0) {
        currentDecodings = prevDecodings;
      }

      // log("currentNumber: %d, ", currentNumber);

      currentNumber = stoi(s.substr(i - 1, 2));

      if (currentNumber >= 10 && currentNumber <= 26) {
        currentDecodings += prevPrevDecodings;
      }

      // log("currentNumber: %d, ", currentNumber);

      if (currentDecodings == 0) {
        return 0;
      }

      prevPrevDecodings = prevDecodings;
      prevDecodings = currentDecodings;
      currentDecodings = 0;

      // log("prevPrevDecodings:%d, prevDecodings:%d\n", prevPrevDecodings,
      //     prevDecodings);
    }

    return prevDecodings;
  }
};

int main() {
  Solution sol;

  string s = "106";

  log("Number of decodings: %d\n", sol.numDecodings(s));
}
