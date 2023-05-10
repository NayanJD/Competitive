#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
		unordered_set<int> visited;
		
		int n = grid.size(), m = grid[0].size(), islands = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 0 && visited.find(i * m + j) == visited.end()){
					//printf("-------Testing for i: %d, j: %d\n", i, j);
					if(isIsland(grid, i, j, n, m, visited)) {
						islands++;
					}
				}
			}
		}

		return islands;
    }

	bool isIsland(vector<vector<int>>& grid, int i, int j, int n, int m, unordered_set<int>& visited) {
		if(i == n || i < 0 || j == m || j < 0) {
			//printf("Out of bounds i: %d, j: %d\n", i , j);
			return false;
		}
		
		if(visited.find(i * m + j) != visited.end()){
			return true;
		}

		if(grid[i][j] == 1) {
			return true;
		}
		
		//printf("crawling i: %d, j: %d\n", i , j);
		visited.insert(i * m + j);
		
		bool isChildIsland = isIsland(grid, i + 1, j, n, m, visited);

		isChildIsland = isChildIsland && isIsland(grid, i - 1, j, n, m, visited);

		isChildIsland = isChildIsland && isIsland(grid, i, j + 1, n, m, visited);

		isChildIsland = isChildIsland && isIsland(grid, i, j - 1, n, m, visited); 

		return isChildIsland; 

	}
};

void print2D(vector<vector<int>>& arr){
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr[i].size(); j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	Solution sol;

	vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

	//printf("Islands: %d\n", sol.closedIsland(grid));

	//grid = {{0,0,1,0,0},{0,1,0,1,0},{0,1,1,1,0}};

	//printf("Islands: %d\n", sol.closedIsland(grid));

	grid = {{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};
	
	print2D(grid);
	printf("Islands: %d\n", sol.closedIsland(grid));
}
