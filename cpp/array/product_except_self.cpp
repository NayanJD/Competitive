// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 
`
// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 1);

        int currMul = 1;

        for(int i = n - 1; i >= 0; i--){
            currMul *= nums[i];
            result[i] = currMul;
        }

        currMul = 1;
        for(int i = 0; i < n; i++){
            if(i < n-1){
                result[i] = result[i+1] * currMul;
            } else {
                result[i] = currMul;
            }

            currMul *= nums[i];
        }

        return result;
    }
};


int main(){

    Solution sol;

    // vector<int> t = {1,2,3,4};
    vector<int> t = {-1,1,0,-3,3};


    vector<int> r = sol.productExceptSelf(t);

    for(int item: r){
        printf("%d, ", item);
    }

    return 0;
}