// https://leetcode.com/problems/climbing-stairs/description/
//
// 70. Climbing stairs
//
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?
//
// Example 1:
//
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:
//
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
//
//
// Constraints:
//
// 1 <= n <= 45

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) { return fibonacciNthNumber(n); }

  int fibonacciNthNumber(int n) {
    vector<vector<unsigned int>> a(2, vector<unsigned int>(2, 1)),
        result(2, vector<unsigned int>(2, 1));

    a[1][1] = 0;

    result[0][1] = 0;
    result[1][0] = 0;

    while (n > 0) {
      if ((n & 1) == 1) {
        result = matrixMultiplication4x4(result, a);
      }

      n >>= 1;

      a = matrixMultiplication4x4(a, a);
    }

    return result[0][0];
  }

  vector<vector<unsigned int>>
  matrixMultiplication4x4(vector<vector<unsigned int>> a,
                          vector<vector<unsigned int>> b) {
    vector<vector<unsigned int>> result(2, vector<unsigned int>(2));

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
      }
    }
    return result;
  }
};

int main() {

  Solution sol;

  int n = 45;
  // int n = 1;

  // int n = 2;

  // int n = 3;

  printf("Total ways to climb stairs: %d\n", sol.climbStairs(n));
}
