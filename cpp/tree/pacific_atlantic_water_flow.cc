// https://leetcode.com/problems/pacific-atlantic-water-flow/description/
//
// The solution does not passes the test case on line 118
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

class Solution {
  int n, m;

  // unordered_map<vector<int>, bool> pacificVisited, atlanticVisited;
  vector<vector<int>> p, a;

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    n = heights.size();
    m = heights[0].size();

    p.resize(n);
    fill(p.begin(), p.end(), vector<int>(m, -1));

    a.resize(n);
    fill(a.begin(), a.end(), vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dfs(i, j, heights);
      }
    }

    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] && p[i][j])
          result.push_back({i, j});
      }
    }

    return result;
  }

  void dfs(int i, int j, vector<vector<int>> &heights) {
    if (p[i][j] != -1 || a[i][j] != -1) {
      return;
    }

    p[i][j] = 0;
    a[i][j] = 0;

    if (i == (n - 1)) {
      a[i][j] = 1;
    } else if (heights[i][j] >= heights[i + 1][j]) {
      dfs(i + 1, j, heights);
      p[i][j] = p[i][j] || p[i + 1][j];
      a[i][j] = a[i][j] || a[i + 1][j];
    }

    if (j == (m - 1)) {
      a[i][j] = 1;
    } else if (heights[i][j] >= heights[i][j + 1]) {
      dfs(i, j + 1, heights);
      p[i][j] = p[i][j] || p[i][j + 1];
      a[i][j] = a[i][j] || a[i][j + 1];
    }

    if (i == 0) {
      p[i][j] = 1;
    } else if (heights[i][j] >= heights[i - 1][j]) {
      dfs(i - 1, j, heights);
      p[i][j] = p[i][j] || p[i - 1][j];
      a[i][j] = a[i][j] || a[i - 1][j];
    }

    if (j == 0) {
      p[i][j] = 1;
    } else if (heights[i][j] >= heights[i][j - 1]) {
      dfs(i, j - 1, heights);
      p[i][j] = p[i][j] || p[i][j - 1];
      a[i][j] = a[i][j] || a[i][j - 1];
    }

    return;
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
  //
  vector<vector<int>> heights = {{3, 3, 3}, {3, 1, 3}, {0, 2, 4}};

  print2D(sol.pacificAtlantic(heights));
}
