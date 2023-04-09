// https://leetcode.com/problems/dungeon-game/description/
//
// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
//
//The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
//
//Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
//
//To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
//
//Return the knight's minimum initial health so that he can rescue the princess.
//
//Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
//
//Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
//Output: 7
//Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
//Example 2:
//
//Input: dungeon = [[0]]
//Output: 1
// 
//
//Constraints:
//
//m == dungeon.length
//n == dungeon[i].length
//1 <= m, n <= 200
//-1000 <= dungeon[i][j] <= 1000

#include<iostream>
#include<queue>

using namespace std;

void showQ(priority_queue<vector<int>, vector<vector<int>>> pq) {
    while(!pq.empty()){
        auto q = pq.top();
        pq.pop();
        printf("(%d, %d, %d), ", q[0], q[1], q[2]);
    }
    printf("\n");
}

void showDP(vector<vector<vector<int>>> dp){
    for(auto row: dp){
        for(auto column: row){
            printf("(%d,%d), ", column[0], column[1]);
        }
        printf("\n");
    }
}

// My Solution (15ms)
//
//class Solution {
//public:
//    int calculateMinimumHP(vector<vector<int>>& dungeon) {
//
//        vector<vector<vector<int>>> dp;
//        
//        int m = dungeon.size(), n = dungeon[0].size();
//
//        for(int i = 0; i < m; i++){
//            dp.push_back({});
//            for(int j = 0; j < n; j++){
//                dp[i].push_back({(int)10e8, (int)10e8});
//            }
//        }
//        
//        int val = dungeon[m-1][n-1] < 0 ? -1 * dungeon[m-1][n-1]  : 0;
//        dp[m-1][n-1] = {val + 1, val + 1};
//        
//        vector<int> curr;
//        for(int i = m - 1; i > -1; i--){
//            for(int j = n - 1; j > -1; j--){
//                curr.clear();
//                if(i + 1 < m) {
//                    dp[i][j][0] = min(dp[i+1][j][0], dp[i+1][j][1]) - dungeon[i][j];
//
//                    if(dp[i][j][0] < 1) {
//                        dp[i][j][0] = 1;
//                    }
//                }
//
//                if(j + 1 < n) {
//                    dp[i][j][1] = min(dp[i][j+1][0], dp[i][j+1][1]) - dungeon[i][j];
//
//                    if(dp[i][j][1] < 1) {
//                        dp[i][j][1] = 1;
//                    }
//                }
//            }
//        }
//
//        //printf("------------DP Now--------------\n");
//        //showDP(dp);
//        //printf("\n");
//        return min(dp[0][0][0],dp[0][0][1]); 
//    }
//};


// 3ms solution
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<int> curr_intitial_health(cols);
        vector<int> next_intitial_health(cols);

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                int health = dungeon[i][j];
                int req_right, req_down, req;

                if (i == rows - 1 && j == cols - 1)
                {
                    curr_intitial_health[j] = max(1, 1 - health);
                    continue;
                }

                if (i == rows - 1)
                {
                    req_right = curr_intitial_health[j + 1];
                    curr_intitial_health[j] = max(1, req_right - health);
                    continue;
                }

                if (j == cols - 1)
                {
                    req_down = next_intitial_health[j];
                    curr_intitial_health[j] = max(1, req_down - health);
                    continue;
                }

                req_right = curr_intitial_health[j + 1];
                req_down = next_intitial_health[j];
                req = min(req_right, req_down);

                curr_intitial_health[j] = max(1, req - health);
            }

            for (int j = cols - 1; j >= 0; j--)
            {
                next_intitial_health[j] = curr_intitial_health[j];
            }
        }

        return curr_intitial_health[0];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> t1 = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    printf("MinPower: %d\n", sol.calculateMinimumHP(t1));

    vector<vector<int>> t2 = {{0}};
    printf("MinPower: %d\n", sol.calculateMinimumHP(t2));

    vector<vector<int>> t3 = {{0,0}};
    printf("MinPower: %d\n", sol.calculateMinimumHP(t3));
}
