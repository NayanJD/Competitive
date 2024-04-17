// https://leetcode.com/problems/house-robber
//
// 198. House house
//
// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security systems
// connected and it will automatically contact the police if two adjacent houses
// were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the
// police.
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:
//
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
// (money = 1). Total amount you can rob = 2 + 9 + 1 = 12.
//
//
// Constraints:
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400

#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

class Solution {
public:
  int rob(vector<int> &nums) {
    int prevMoney{nums[0]}, prevPrevMoney{nums[0]};

    if (nums.size() == 1) {
      return nums[0];
    }

    if (nums[1] > nums[0]) {
      prevMoney = nums[1];
    }

    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] + prevPrevMoney > prevMoney) {
        prevPrevMoney = nums[i] + prevPrevMoney;
        swap(prevMoney, prevPrevMoney);
      } else {
        prevPrevMoney = prevMoney;
      }
    }

    return prevMoney;
  }
};

int main() {

  Solution sol;

  // vector<int> nums = {1, 2, 3, 1};
  vector<int> nums = {2, 7, 9, 3, 1};

  log("Maximum money: %d\n", sol.rob(nums));

  return 0;
}
