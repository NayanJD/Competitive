// https://leetcode.com/explore/interview/card/google/59/array-and-strings/3049/
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

// #include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

void showVector2n(vector<int>& nums) {

    for(int j = 0; j < nums.size(); j++){
        printf("%d, ", nums[j]);
    }

    cout << endl;
    
}

void showVector(vector<vector<int>> nums) {
    printf("[");
    for(int i = 0; i < nums.size(); i++){
        printf("[");
        for(int j = 0; j < nums[i].size(); j++){
            printf("%d, ", nums[i][j]);
        }

        printf("], ");

    }

    printf("]\n");
}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        // showVector2n(nums);

        int n = nums.size();
        
        map<vector<int>, int> seen;

        for(int i = 0; i < n; i++) {
            // printf("For nums[i] %d\n", nums[i]);

            vector<int> pair;
            int sum;

            for(int j = i + 1, k = n - 1; j < k; ){
                // printf("%d %d\n", j, k);


                sum = nums[j] + nums[k];

                // printf("sum: %d\n", sum);
                if(sum == -nums[i]){
                    // printf("Got one\n");
                    pair = {nums[i], nums[j], nums[k]};

                    // result.push_back(pair);
                    seen[pair] = 1;
                    j++;
                    k--;
                } else if (sum < -nums[i]){
                    j++;
                } else if (sum > -nums[i]) {
                    k--;
                }

                
            }
        }

        for(auto pair: seen){
            result.push_back(pair.first);
        }

        return result;
    }
};

int main() {
    Solution s;

    vector<int> t1 = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    // -4 
    vector<int> t2 = {-1,0,1,2,-1,-4};

    showVector(s.threeSum(t1));
    showVector(s.threeSum(t2));

}

