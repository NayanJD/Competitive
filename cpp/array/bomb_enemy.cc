//https://leetcode.com/problems/bomb-enemy/

// Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.
// 
// The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.
// 
//  
// 
// Example 1:
// Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
// Output: 3
// 
// Example 2:
// Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
// Output: 1
// 
// Constraints:
// 
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 'W', 'E', or '0'.

#include<iostream>
#include<vector>

using namespace std;

void print2D(vector<vector<int>> grid){
	int n = grid.size(), m = grid[0].size();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> casualtyCount(n);
		for(int i = 0; i < n; i++){
			casualtyCount[i] = vector<int>(m);
		}
		
		int currCount = 0;
		for(int i = 0; i < n; i++) {
			currCount = 0;
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 'W'){
					currCount = 0;
				} else if(grid[i][j] == 'E') {
					casualtyCount[i][j] += currCount;
					currCount++;
				} else {
					casualtyCount[i][j] = currCount;
				}
			}

			currCount = 0;
			for(int j = m - 1; j >= 0; j--){
				if(grid[i][j] == 'W'){
					currCount = 0;
				} else if(grid[i][j] == 'E') {
					casualtyCount[i][j] += currCount;
					currCount++;
				} else {
					casualtyCount[i][j] += currCount;
				}
			}
		}
		
		//print2D(casualtyCount);

		int maxKilledEnemies = 0;
		for(int j = 0; j < m; j++) {
			currCount = 0;
			for(int i = 0; i < n; i++){
				if(grid[i][j] == 'W'){
					currCount = 0;
				} else if(grid[i][j] == 'E') {
					casualtyCount[i][j] += currCount;
					currCount++;
				} else {
					casualtyCount[i][j] += currCount;
				}
			}

			currCount = 0;
			for(int i = n - 1; i >= 0; i--){
				if(grid[i][j] == 'W'){
					currCount = 0;
				} else if(grid[i][j] == 'E') {
					casualtyCount[i][j] += currCount;
					currCount++;
				} else {
					casualtyCount[i][j] += currCount;
					maxKilledEnemies = max(maxKilledEnemies, casualtyCount[i][j]);
				}
			}
		}
		
		//print2D(casualtyCount);

		return maxKilledEnemies;	
    }
};

int main() {
	Solution sol;

	vector<vector<char>> grid = {{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};

	//printf("Max Killed Enemies: %d\n", sol.maxKilledEnemies(grid));

	grid = {{'E','W','E'},{'0','0','0'},{'E','E','E'}};

	printf("Max Killed Enemies: %d\n", sol.maxKilledEnemies(grid));

}
