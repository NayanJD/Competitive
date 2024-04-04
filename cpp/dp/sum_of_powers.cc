// https : // leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers
//
// 2787. Ways to Express an Integer as Sum of Powers
//
// Given two positive integers n and x.
//
// Return the number of ways n can be expressed as the sum of the xth power of
// unique positive integers, in other words, the number of sets of unique
// integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
//
// Since the result can be very large, return it modulo 109 + 7.
//
// For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.
//
//
//
// Example 1:
//
// Input: n = 10, x = 2
// Output: 1
// Explanation: We can express n as the following: n = 32 + 12 = 10.
// It can be shown that it is the only way to express 10 as the sum of the 2nd
// power of unique integers. Example 2:
//
// Input: n = 4, x = 1
// Output: 2
// Explanation: We can express n in the following ways:
// - n = 41 = 4.
// - n = 31 + 11 = 4.
//
//
// Constraints:
//
// 1 <= n <= 300
// 1 <= x <= 5

#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

class Solution {
public:
  int numberOfWays(int n, int x) {

    vector<int> prevDp(n + 1, 0), dp(n + 1, 0);

    prevDp[0] = 1;
    dp[0] = 1;

    int currentNum{1}, exponentNum{1};

    while (exponentNum <= n) {

      for (int i = exponentNum; i <= n; i++) {
        dp[i] = (dp[i] + prevDp[i - exponentNum]) % (int)(1e9 + 7);
      }

      currentNum++;
      exponentNum = (int)pow(currentNum, x);

      for (int i = 1; i <= n; i++) {
        prevDp[i] = dp[i];
      }
    }

    return dp[n];
  }
};

int main() {
  Solution sol;

  // int n = 10;
  // int x = 2;

  // int n = 4;
  // int x = 1;

  int n = 213;
  int x = 1;

  log("Ways to express: %d\n", sol.numberOfWays(n, x));
}
