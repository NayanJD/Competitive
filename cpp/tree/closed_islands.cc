#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
		unordered_set<int> visited;
		
		int n = grid.size(), m = grid[0].size();
		int islands = 0, node = 0, e, f;
		bool localDidFindEnd,isIsland;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(grid[i][j] == 0 && visited.find(i * m + j) == visited.end()){
					printf("Found unvisited\n");
					queue<int> q;

					q.push(i * m + j);
					
					isIsland = true;
					while(!q.empty()) {
						node = q.front();
						q.pop();
						
					    e = node / m;
						f = node % m;

						printf("e: %d, f: %d\n", e, f);	

						localDidFindEnd = false;
						for(int k = f + 1; k < m; k++){
							if(visited.find(e * m + k) != visited.end()){
								continue;
							}

							if(grid[e][k] == 1){
								localDidFindEnd = true;
								break;
							} else {
								visited.insert(e * m + k);
								q.push(e* m + k);
							}
						}
						
						printf("%d ", localDidFindEnd);
						isIsland = localDidFindEnd && isIsland;

						localDidFindEnd = false;
						for(int k = f - 1; k >= 0; k--){
							if(visited.find(e * m + k) != visited.end()){
								continue;
							}

							if(grid[e][k] == 1){
								localDidFindEnd = true;
								break;
							} else {
								visited.insert(e * m + k);
								q.push(e * m + k);
							}
						}
						
						printf("%d ", localDidFindEnd);

						isIsland = localDidFindEnd && isIsland;

						localDidFindEnd = false;
						for(int k = e - 1; k >= 0; k--){
							if(visited.find(k * m + f) != visited.end()){
								continue;
							}

							if(grid[k][f] == 1){
								localDidFindEnd = true;
								break;
							} else {
								visited.insert(k * m + f);
								q.push(k * m + f);
							}
						}

						printf("%d ", localDidFindEnd);

						isIsland = localDidFindEnd && isIsland;

						localDidFindEnd = false;
						for(int k = e + 1; k < n; k++){
							if(visited.find(k * m + f) != visited.end()){
								continue;
							}

							if(grid[k][f] == 1){
								localDidFindEnd = true;
								break;
							} else {
								visited.insert(k * m + f);
								q.push(k * m + f);
							}
						}

						printf("%d\n", localDidFindEnd);

						isIsland = localDidFindEnd && isIsland;
						
					}
					
					printf("isIsland: %d\n", isIsland);
					if(isIsland){
						islands++;
					}

				}
			}
		}

		return islands;
    }
};

int main() {
	Solution sol;

	vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

	printf("Islands: %d\n", sol.closedIsland(grid));
}
