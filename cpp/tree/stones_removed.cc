// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
//
//  On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
// 
// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
// 
//  
// 
// Example 1:
// 
// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
// Explanation: One way to remove 5 stones is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,1].
// 2. Remove stone [2,1] because it shares the same column as [0,1].
// 3. Remove stone [1,2] because it shares the same row as [1,0].
// 4. Remove stone [1,0] because it shares the same column as [0,0].
// 5. Remove stone [0,1] because it shares the same row as [0,0].
// Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
// Example 2:
// 
// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
// Explanation: One way to make 3 moves is as follows:
// 1. Remove stone [2,2] because it shares the same row as [2,0].
// 2. Remove stone [2,0] because it shares the same column as [0,0].
// 3. Remove stone [0,2] because it shares the same row as [0,0].
// Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
// Example 3:
// 
// Input: stones = [[0,0]]
// Output: 0
// Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
//  
// 
// Constraints:
// 
// 1 <= stones.length <= 1000
// 0 <= xi, yi <= 104
// No two stones are at the same coordinate point.

#include<iostream>
#include<unordered_map>
#include<set>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
		int result = 0;
        unordered_map<int,vector<vector<int>>> rowAdj, colAdj;
		
		int n = stones.size();

		for(int i = 0; i < n; i++){
			if(rowAdj.find(stones[i][0]) == rowAdj.end()){
				rowAdj[stones[i][0]] = {stones[i]};
			} else {
				rowAdj[stones[i][0]].push_back(stones[i]);
			}

			if(colAdj.find(stones[i][1]) == colAdj.end()){
				colAdj[stones[i][1]] = {stones[i]};
			} else {
				colAdj[stones[i][1]].push_back(stones[i]);
			}
		}
	
		set<vector<int>> visited, currVisited;
		
		for(int i = 0; i < n; i++){
			visited.insert(stones[i]);
		}
		
		queue<vector<int>> q;
		vector<int> currNode;
//		printf("Starting\n");
		while(!visited.empty()){
			auto node = *visited.begin();

			q.empty();
			q.push(node);

//			printf("Node: %d,%d\n", node[0], node[1]);

			while(!q.empty()) {
				currNode = q.front();
				q.pop();

				currVisited.insert(currNode); 
				
				if(rowAdj.find(currNode[0]) != rowAdj.end()){
					for(auto itr = rowAdj[currNode[0]].begin(); itr != rowAdj[currNode[0]].end(); itr++){
						if(currVisited.find(*itr) == currVisited.end()) {
							
						   	q.push(*itr);
					    }
					    
					}
				}

				if(colAdj.find(currNode[1]) != colAdj.end()){
					for(auto itr = colAdj[currNode[1]].begin(); itr != colAdj[currNode[1]].end(); itr++){
						if(currVisited.find(*itr) == currVisited.end()) {
							q.push(*itr);
						}
					
					}
				}
				
			}
			
			for(auto itr = currVisited.begin(); itr != currVisited.end(); itr++){
//				printf("Erasing: %d,%d\n", (*itr)[0], (*itr)[1]);
				visited.erase(*itr);
			}

			result++;
		}

		return n - result;
    }
};

int main() {
	Solution sol;

	vector<vector<int>> t1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
	printf("Stones removed: %d\n", sol.removeStones(t1));

	t1 = {{0,0},{0,2},{1,1},{2,0},{2,2}};
	printf("Stones removed: %d\n", sol.removeStones(t1));
}
