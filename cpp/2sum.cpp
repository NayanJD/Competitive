// https://leetcode.com/problems/two-sum/
// Given an array of integers nums and an integer target, return indices of the
// two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void showVector(vector<int> &nums) {

  for (int j = 0; j < nums.size(); j++) {
    printf("%d, ", nums[j]);
  }

  cout << endl;
}
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> indexMap;
    int n = nums.size();

    int reducedVal;

    vector<int> result(2, 0);

    for (int i = 0; i < n; i++) {
      reducedVal = target - nums[i];

      // printf("reducedVal: %d\n", reducedVal);
      if (indexMap.find(reducedVal) != indexMap.end() &&
          indexMap[reducedVal] != i) {
        result[0] = i;
        result[1] = indexMap[reducedVal];
        break;
      }

      indexMap[nums[i]] = i;
    }

    return result;
  }
};

int main() {
  Solution s;

  vector<int> t1 = {2, 7, 11, 15};
  vector<int> t2 = {3, 2, 4};
  vector<int> t3 = {3, 3};

  vector<int> ans;

  ans = s.twoSum(t1, 9);
  showVector(ans);

  ans = s.twoSum(t2, 6);
  showVector(ans);

  ans = s.twoSum(t3, 6);
  showVector(ans);

  return 0;
}
