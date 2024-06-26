// https://leetcode.com/problems/shortest-path-to-get-food
//
//
// You are starving and you want to eat food as quickly as possible. You want to
// find the shortest path to arrive at any food cell.

// You are given an m x n character matrix, grid, of these different types of
// cells:
//
// '*' is your location. There is exactly one '*' cell.
// '#' is a food cell. There may be multiple food cells.
// 'O' is free space, and you can travel through these cells.
// 'X' is an obstacle, and you cannot travel through these cells.
// You can travel to any adjacent cell north, east, south, or west of your
// current location if there is not an obstacle.
//
// Return the length of the shortest path for you to reach any food cell. If
// there is no path for you to reach food, return -1.
//
// Example 1:
// Input: grid =
// [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
// Output: 3
// Explanation: It takes 3 steps to reach the food.
//
// Example 2:
//
// Input: grid =
// [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
// Output: -1
// Explanation: It is not possible to reach the food.
//
// Example 3:
//
// Input: grid =
// [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
// Output: 6
// Explanation: There can be multiple food cells. It only takes 6 steps to reach
// the bottom food.
//
//
// Constraints:
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// grid[row][col] is '*', 'X', 'O', or '#'.
// The grid contains exactly one '*'.

#include <functional>
#include <queue>
#include <stdio.h>
#include <unordered_set>
#include <utility>
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

public:
  int getFood(vector<vector<char>> &grid) {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                   greater<pair<int, vector<int>>>>
        q;

    int n = grid.size(), m = grid[0].size();

    this->n = n;
    this->m = m;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '*') {
          q.push({0, {i, j}});
        }
      }
    }

    unordered_set<int> visited;

    while (!q.empty()) {
      auto top = q.top();
      q.pop();

      int i = top.second[0];
      int j = top.second[1];

      // log("visiting: %d, %d, %d\n", i, j, top.first);

      if (grid[i][j] == '#') {
        return top.first;
      }

      if (j + 1 < m && grid[i][j] != 'X' &&
          visited.find(getHash(i, j + 1)) == visited.end()) {
        visited.insert(getHash(i, j + 1));
        q.push({top.first + 1, {i, j + 1}});
      }

      if (i + 1 < n && grid[i][j] != 'X' &&
          visited.find(getHash(i + 1, j)) == visited.end()) {
        visited.insert(getHash(i + 1, j));
        q.push({top.first + 1, {i + 1, j}});
      }

      if (j - 1 >= 0 && grid[i][j] != 'X' &&
          visited.find(getHash(i, j - 1)) == visited.end()) {
        visited.insert(getHash(i, j - 1));
        q.push({top.first + 1, {i, j - 1}});
      }

      if (i - 1 >= 0 && grid[i][j] != 'X' &&
          visited.find(getHash(i - 1, j)) == visited.end()) {
        visited.insert(getHash(i - 1, j));
        q.push({top.first + 1, {i - 1, j}});
      }
    }

    return -1;
  }

  int getHash(int i, int j) { return i * m + j; }
};

int main() {
  Solution sol;

  // vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X', 'X'},
  //                              {'X', '*', 'O', 'O', 'O', 'X'},
  //                              {'X', 'O', 'O', '#', 'O', 'X'},
  //                              {'X', 'X', 'X', 'X', 'X', 'X'}};
  //
  //
  //

  // vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X'},
  //                              {'X', '*', 'X', 'O', 'X'},
  //                              {'X', 'O', 'X', '#', 'X'},
  //                              {'X', 'X', 'X', 'X', 'X'}};

  vector<vector<char>> grid = {{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                               {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
                               {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
                               {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
                               {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};

  // vector<vector<char>> grid = {{'#', 'O', 'O'}, {'O', '*', 'O'}};

  log("Shortest path: %d\n", sol.getFood(grid));
}
