// https://leetcode.com/problems/number-of-closed-islands/
// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
// 
// Return the number of closed islands.
// 
//  
// 
// Example 1:
// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
// 
// Example 2:
// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
// 
// Example 3:
// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2
// 
// Constraints:
// 
// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1

#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

void print2D(vector<vector<int>>& arr){
	int n = arr.size(), m = arr[0].size();
	
	printf("n: %d, m: %d\n", n, m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
		unordered_set<int> visited;
		
		int n = grid.size(), m = grid[0].size(), islands = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 0){
					//printf("-------Testing for i: %d, j: %d\n", i, j);
					
					if(isIsland(grid, i, j, n, m)) {
						islands++;
						//print2D(grid);
					}
					
				}
			}
		}

		return islands;
    }

	bool isIsland(vector<vector<int>>& grid, int i, int j, int n, int m) {
		if(i == n || i < 0 || j == m || j < 0) {
			//printf("Out of bounds i: %d, j: %d\n", i , j);
			return false;
		}
		

		if(grid[i][j] == 1) {
			return true;
		}
		
		//printf("crawling i: %d, j: %d\n", i , j);

		grid[i][j] = 1;
		
		bool isChildIsland = isIsland(grid, i + 1, j, n, m);
		
		//printf("checking i: %d, j: %d\n", i - 1, j);
		isChildIsland = isIsland(grid, i - 1, j, n, m) && isChildIsland;

		//printf("checking i: %d, j: %d\n", i, j + 1);
		isChildIsland = isIsland(grid, i, j + 1, n, m) && isChildIsland;

		//printf("checking i: %d, j: %d\n", i, j - 1);
		isChildIsland = isIsland(grid, i, j - 1, n, m) && isChildIsland; 

		return isChildIsland; 

	}
};


int main() {
	Solution sol;

	//vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

	//printf("Islands: %d\n", sol.closedIsland(grid));

	//grid = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};

	//printf("Islands: %d\n", sol.closedIsland(grid));

	vector<vector<int>> grid = {{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};
	
	//print2D(grid);
	printf("Islands: %d\n", sol.closedIsland(grid));
}
