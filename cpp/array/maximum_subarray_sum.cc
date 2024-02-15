// https://leetcode.com/problems/maximum-subarray

// 53. Maximum Subarray

// Given an integer array nums, find the subarray with the largest sum, and
// return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// Follow up: If you have figured out the O(n) solution, try coding another
// solution using the divide and conquer approach, which is more subtle.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int result = -__INT_MAX__, currentSum = 0;

    for (int &num : nums) {
      if (currentSum + num < num) {
        currentSum = num;
      } else {
        currentSum += num;
      }

      result = max(result, currentSum);
    }

    return result;
  }
};

int main() {
  Solution sol;

  // vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  // vector<int> nums = {-3, -2, -1};

  vector<int> nums = {5, 4, -1, 7, 8};

  printf("Max Sub Array Sum: %d\n", sol.maxSubArray(nums));
}
