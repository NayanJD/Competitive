// https://leetcode.com/problems/number-of-islands/
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int islandCount = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    recursivePass(grid, i, j, m, n);
                }
            }
        }

        return islandCount;
    }

    void recursivePass(vector<vector<char>>& grid, int i, int j, int m, int n){
        grid[i][j] = '0';

        if(i - 1 >= 0 && grid[i - 1][j] == '1'){
            recursivePass(grid, i - 1, j, m, n);
        }

        if(j + 1 < n && grid[i][j + 1] == '1'){
            recursivePass(grid, i, j + 1, m, n);
        }

        if(i + 1 < m && grid[i + 1][j] == '1'){
            recursivePass(grid, i + 1, j, m, n);
        }

        if(j - 1 >= 0 && grid[i][j - 1] == '1'){
            recursivePass(grid, i, j - 1, m, n);
        }

        

        return;
    }

    int doesHaveAdjacentLand(vector<vector<char>>& grid, int& i, int& j, int& m, int& n){
        if(i - 1 >= 0 && grid[i - 1][j] == '1'){
            return 1;
        }

        if(j - 1 >= 0 && grid[i][j - 1] == '1'){
            return 1;
        }

        return 0;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // vector<vector<char>> grid = {
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    // };

    printf("Number of islands: %d", sol.numIslands(grid));

    return 0;
}