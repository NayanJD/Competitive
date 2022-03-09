// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3053/
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canTakeStep = 1;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(canTakeStep == 0){
                return false;
            }

            canTakeStep--;

            canTakeStep = max(canTakeStep, nums[i]);

            if(i + canTakeStep >= n - 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    vector<int> t1 = {2,3,1,1,4};
    vector<int> t2 = {3,2,1,0,4};

    Solution sol;

    printf("canReach: %d\n", sol.canJump(t1));
    printf("canReach: %d", sol.canJump(t2));

    return 0;
}