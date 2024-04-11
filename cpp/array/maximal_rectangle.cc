// https://leetcode.com/problems/maximal-rectangle/description/
//
// 85. Maximal maximalRectangle
//
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest
// rectangle containing only 1's and return its area.

// Example 1:
//
// Input: matrix =
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:
//
// Input: matrix = [["0"]]
// Output: 0
// Example 3:
//
// Input: matrix = [["1"]]
// Output: 1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {

    int n = matrix.size(), m = matrix[0].size();

    vector<int> dpHeight(m), stack, dpRectangle(m);
    int maxRectangle = 0;

    for (int i = 0; i < n; i++) {
      // printf("For i: %d\n ", i);

      for (int j = 0; j < m; j++) {

        if (matrix[i][j] == '1') {
          dpHeight[j] = dpHeight[j] + 1;

        } else {
          dpHeight[j] = 0;
        }
      }

      // printf("Forward: ");
      for (int j = 0; j < m; j++) {
        while (!stack.empty() && dpHeight[stack.back()] > dpHeight[j]) {

          dpRectangle[stack.back()] =
              (j - stack.back() - 1) * dpHeight[stack.back()];

          // printf("(l: %d, b: %d), ", dpHeight[stack.back()],
          //        (j - stack.back() - 1));

          stack.pop_back();
        }
        stack.push_back(j);
      }

      // printf("| ");
      while (!stack.empty()) {
        dpRectangle[stack.back()] =
            (m - stack.back() - 1) * dpHeight[stack.back()];

        // printf("(l: %d, b: %d), ", dpHeight[stack.back()],
        //        (m - stack.back() - 1));

        stack.pop_back();
      }

      // printf("\n");

      // printf("Backwards: ");

      for (int j = m - 1; j >= 0; j--) {
        while (!stack.empty() && dpHeight[stack.back()] > dpHeight[j]) {

          dpRectangle[stack.back()] +=
              (stack.back() - j - 1) * dpHeight[stack.back()];

          // printf("(l: %d, b: %d), ", dpHeight[stack.back()],
          //        (stack.back() - j - 1));

          maxRectangle = max(maxRectangle, dpRectangle[stack.back()] +
                                               dpHeight[stack.back()]);

          stack.pop_back();
        }
        stack.push_back(j);
      }

      // printf("|||");
      while (!stack.empty()) {
        dpRectangle[stack.back()] += (stack.back()) * dpHeight[stack.back()];

        // printf("(l: %d, b: %d), ", dpHeight[stack.back()], (stack.back()));

        maxRectangle = max(maxRectangle,
                           dpRectangle[stack.back()] + dpHeight[stack.back()]);

        stack.pop_back();
      }

      fill(dpRectangle.begin(), dpRectangle.end(), 0);

      // printf("\n");
    }

    return maxRectangle;
  }
};

int main() {

  Solution sol;

  // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
  //                                {'1', '0', '1', '1', '1'},
  //                                {'1', '1', '1', '1', '1'},
  //                                {'1', '0', '0', '1', '0'}};

  // vector<vector<char>> matrix = {{'0'}};

  // vector<vector<char>> matrix = {{'0', '1', '1'}};

  vector<vector<char>> matrix = {{'1', '0', '1', '1', '1'},
                                 {'0', '1', '0', '1', '1'},
                                 {'1', '1', '0', '1', '1'},
                                 {'1', '1', '0', '1', '1'},
                                 {'0', '1', '1', '1', '1'}};

  // vector<vector<char>> matrix = {{'1', '0', '0', '0', '1'},
  //                                {'1', '1', '0', '1', '1'},
  //                                {'1', '1', '1', '1', '1'}};
  printf("Maximal Rectangle: %d\n", sol.maximalRectangle(matrix));
}
