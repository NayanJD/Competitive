#include <stdio.h>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

void print2DBool(vector<vector<bool>> arr) {
  printf("[");
  for (int i = 0; i < arr.size(); i++) {
    printf("[");
    for (int j = 0; j < arr[i].size(); j++) {
      printf("%s,", arr[i][j] ? "true" : "false");
    }
    printf("]");
  }
  printf("]\n");
}

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> dp(n, vector<bool>(m, false)),
        atlanticDp(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = true;
        } else {
          if (dp[i - 1][j] && heights[i - 1][j] <= heights[i][j]) {
            dp[i][j] = true;
          }

          if (dp[i][j - 1] && heights[i][j - 1] <= heights[i][j]) {
            dp[i][j] = true;
          }
        }
      }
    }

    // log("Left parse dp\n");
    // print2DBool(dp);

    vector<vector<int>> result;

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {

        if (i == (n - 1) || j == (m - 1)) {
          atlanticDp[i][j] = true;
        } else {
          if (atlanticDp[i + 1][j] && heights[i + 1][j] <= heights[i][j]) {
            atlanticDp[i][j] = true;
          }

          if (atlanticDp[i][j + 1] && heights[i][j + 1] <= heights[i][j]) {
            atlanticDp[i][j] = true;
          }
        }

        if (dp[i][j] && atlanticDp[i][j]) {
          result.push_back({i, j});
        }
      }
    }

    return result;
  }
};

void print2D(vector<vector<int>> arr) {
  printf("[");
  for (int i = 0; i < arr.size(); i++) {
    printf("[");
    for (int j = 0; j < arr[i].size(); j++) {
      printf("%d,", arr[i][j]);
    }
    printf("]");
  }
  printf("]\n");
}

int main() {
  Solution sol;

  // vector<vector<int>> heights = {{1, 2, 2, 3, 5},
  //                                {3, 2, 3, 4, 4},
  //                                {2, 4, 5, 3, 1},
  //                                {6, 7, 1, 4, 5},
  //                                {5, 1, 1, 2, 4}};

  // vector<vector<int>> heights = {{1}};

  vector<vector<int>> heights = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

  print2D(sol.pacificAtlantic(heights));
}
