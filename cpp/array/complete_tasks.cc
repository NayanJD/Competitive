// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks
//
// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

//Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

// 
//
//Example 1:
//
//Input: tasks = [2,2,3,3,2,4,4,4,4,4]
//Output: 4
//Explanation: To complete all the tasks, a possible plan is:
//- In the first round, you complete 3 tasks of difficulty level 2. 
//- In the second round, you complete 2 tasks of difficulty level 3. 
//- In the third round, you complete 3 tasks of difficulty level 4. 
//- In the fourth round, you complete 2 tasks of difficulty level 4.  
//It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
//Example 2:
//
//Input: tasks = [2,3,3]
//Output: -1
//Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
// 
//
//Constraints:
//
//1 <= tasks.length <= 105
//1 <= tasks[i] <= 109
//

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
		int n = tasks.size();
		
		unordered_map<int,int> count;
		for(int i = 0; i < n; i++) {
			if(count.find(tasks[i]) != count.end()) {
				count[tasks[i]]++;
			} else {
				count[tasks[i]] = 1;
			}
		}
		
		int minRounds = 0, currMin;
		
		for(auto itr = count.begin(); itr != count.end(); itr++){
			
			currMin = (int)10e5;
		    //printf("Task: %d\n", itr->first);	
			int i = 0;
			int c = itr->second;

			while(2 * i <= c){
				//printf("arith: %d\n", c - 2 * i);
				if((c - 2 * i) % 3 == 0){
					currMin = min(currMin, i +  (c - 2 * i) / 3);
				}

				i++;
			}
			
			//printf("currMin: %d\n", currMin);
			if(currMin == (int)10e5){
				return -1;
			} else {
				minRounds += currMin;
			}
		}

		return minRounds;
    }
};

int main(){
	Solution sol;

	vector<int> t1 = {2,2,3,3,2,4,4,4,4,4};
	printf("Minimum rounds: %d\n", sol.minimumRounds(t1));

	t1 = {2,2,2,2,3};
	printf("Minimum rounds: %d\n", sol.minimumRounds(t1));
	
}
