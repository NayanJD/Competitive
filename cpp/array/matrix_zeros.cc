// https://leetcode.com/problems/set-matrix-zeroes/description/
//
// 73. Set Matrix Zeroes
//
// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's.
// You must do it in place.
//
// Example 1:
//
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
//
// Example 2:
//
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
//
// Constraints:
//
// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
//
//
// Follow up:
//
// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

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
  void setZeroes(vector<vector<int>> &matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    bool isColumnZero{false};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j == 0) {
          if (matrix[i][j] == 0) {
            isColumnZero = true;
          }

          continue;
        }
        if (matrix[i][j] == 0) {
          if (i != 0)
            matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = n - 1; i >= 0; i--) {

      for (int j = 1; j < m; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
          matrix[i][j] = 0;
      }

      if (isColumnZero) {
        matrix[i][0] = 0;
      }
    }
  }
};

int main() {

  Solution sol;

  // vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  // vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  vector<vector<int>> matrix = {{0, 1, 1, 0}};

  sol.setZeroes(matrix);

  log("[");
  for (auto row : matrix) {
    log("[");
    for (auto cell : row) {
      log("%d, ", cell);
    }
    log("]\n");
  }
  log("]\n");
}
