// https://leetcode.com/problems/house-robber-ii/description/
// This problem is an extension of the problem House Robber 1.
// Here the array is circular. Hence, skipping the problem description.
//
#include <algorithm>
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
  int rob(vector<int> nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    return max(robAlternative(vector<int>(nums.begin(), --nums.end())),
               robAlternative(vector<int>(++nums.begin(), nums.end())));
  }

  int robAlternative(vector<int> nums) {
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

  // vector<int> nums = {2, 3, 2};
  // vector<int> nums = {1, 2, 3, 1};
  // vector<int> nums = {1, 2, 3};
  vector<int> nums = {0};

  log("Maximum money: %d\n", sol.rob(nums));

  return 0;
}
