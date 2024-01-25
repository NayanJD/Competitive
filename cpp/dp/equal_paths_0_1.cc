// https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s

// 2510. Check if There is a Path With Equal Number of 0's And 1's

// You are given a 0-indexed m x n binary matrix grid. You can move from a cell
// (row, col) to any of the cells (row + 1, col) or (row, col + 1).

// Return true if there is a path from (0, 0) to (m - 1, n - 1) that visits an
// equal number of 0's and 1's. Otherwise return false.

// Example 1:

// Input: grid = [[0,1,0,0],[0,1,0,0],[1,0,1,0]]
// Output: true
// Explanation: The path colored in blue in the above diagram is a valid path
// because we have 3 cells with a value of 1 and 3 with a value of 0. Since
// there is a valid path, we return true.

// Example 2:

// Input: grid = [[1,1,0],[0,0,1],[1,0,0]]
// Output: false
// Explanation: There is no path in this grid with an equal number of 0's and
// 1's.

// Constraints:

// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 100
// grid[i][j] is either 0 or 1.

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  static const int MIN = 0;
  static const int MAX = 1;

  bool isThereAPath(vector<vector<int>> &grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();

    const int expected = (rows + cols) / 2;
    if (expected * 2 == rows + cols) {
      return false;
    }

    std::vector<std::vector<int>> memo(cols + 1, std::vector<int>(2));

    for (int row = 1; row <= rows; ++row) {
      for (int col = 1; col <= cols; ++col) {
        memo[col][MIN] = std::min(memo[col][MIN], memo[col - 1][MIN]);
        memo[col][MAX] = std::max(memo[col][MAX], memo[col - 1][MAX]);

        if (grid[row - 1][col - 1] == 1) {
          ++memo[col][MIN];
          ++memo[col][MAX];
        }
      }

      for (int i = 0; i < cols + 1; i++) {
        printf("%d, %d\n", memo[i][MIN], memo[i][MAX]);
      }
    }

    return memo[cols][MIN] <= expected && expected <= memo[cols][MAX];
  }
};

int main() {
  Solution sol;

  vector<vector<int>> grid = {{0, 1, 0, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}};
  /* vector<vector<int>> grid = {{1, 1, 0}, {0, 0, 1}, {1, 0, 0}}; */

  printf("Is there a path: %d\n", sol.isThereAPath(grid));
}
