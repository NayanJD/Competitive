// https://leetcode.com/problems/generate-parentheses
//
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// #include <cstdint>
// Example 1:
//
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:
//
// Input: n = 1
// Output: ["()"]
//
//
// Constraints:
//
// 1 <= n <= 8

#include <iostream>
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
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1, vector<string>());

    dp[0].push_back("");

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        for (auto comb1 : dp[j]) {
          for (auto comb2 : dp[i - 1 - j]) {
            dp[i].push_back("(" + comb1 + ")" + comb2);
          }
        }
      }
    }

    return dp[n];
  }
};

int main() {

  Solution sol;

  int n = 8;

  vector<string> parentheseses = sol.generateParenthesis(n);

  log("Parenthesis list: ");

  for (string parentheses : parentheseses) {
    log("%s, ", parentheses.c_str());
  }

  log("\n");
}
