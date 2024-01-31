// https://leetcode.com/problems/remove-k-digits

// 402. Remove K Digits
//
// Given string num representing a non-negative integer num, and an integer k,
// return the smallest possible integer after removing k digits from num.

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
// which is the smallest. Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output
// must not contain leading zeroes. Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with
// nothing which is 0.

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

#include <iostream>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {

    int i = 1;
    string smallestNum = num.substr(0, 1);

    while (i < num.size()) {

      while (!smallestNum.empty() && num[i] < smallestNum.back() && k > 0) {
        smallestNum.pop_back();
        k--;
      }
      if (num[i] != '0' || (num[i] == '0' && !smallestNum.empty())) {
        // printf("Adding %c\n", num[i]);
        smallestNum += num[i];
      }

      i++;
    }

    if (k > 0)
      smallestNum = smallestNum.substr(0, max((int)smallestNum.size() - k, 0));

    if (smallestNum.size() == 0) {
      return "0";
    } else {
      return smallestNum;
    }
  }
};

int main() {
  Solution sol;

  // string num = "1432219";
  // int k = 3;

  // string num = "101010223456";
  // int k = 2;

  // string num = "10";
  // int k = 2;

  // string num = "112";
  // int k = 1;
  string num = "1234567890";
  int k = 5;

  printf("Smallest number: %s\n", sol.removeKdigits(num, k).c_str());
}
