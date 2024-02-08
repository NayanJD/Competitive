// https://leetcode.com/problems/contains-duplicate-iii/

// 220. Contains Duplicate III

// You are given an integer array nums and two integers indexDiff and valueDiff.

// Find a pair of indices (i, j) such that:

// i != j,
// abs(i - j) <= indexDiff.
// abs(nums[i] - nums[j]) <= valueDiff, and
// Return true if such pair exists or false otherwise.

// Example 1:

// Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
// Output: true
// Explanation: We can choose (i, j) = (0, 3).
// We satisfy the three conditions:
// i != j --> 0 != 3
// abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
// abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
// Example 2:

// Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// Output: false
// Explanation: After trying all the possible pairs (i, j), we cannot satisfy
// the three conditions, so we return false.

// Constraints:

// 2 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 1 <= indexDiff <= nums.length
// 0 <= valueDiff <= 109

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {

    int n = nums.size();

    set<int> presence{nums[0]};
    int lowerItem, upperItem;

    int i = 1, j = 0;

    while (i < n) {

      if (i - j > indexDiff) {
        presence.erase(nums[j]);
        j++;
      }

      lowerItem = nums[i] - valueDiff - 1;
      upperItem = nums[i] + valueDiff + 1;

      if (presence.lower_bound(nums[i] - valueDiff) != presence.begin()) {
        lowerItem = *prev(presence.lower_bound(nums[i] - valueDiff));
      }

      if (presence.upper_bound(nums[i] + valueDiff) != presence.begin()) {
        upperItem = *prev(presence.upper_bound(nums[i] + valueDiff));
      }

      if (abs(nums[i] - lowerItem) <= valueDiff ||
          abs(upperItem - nums[i]) <= valueDiff) {
        return true;
      }

      presence.insert(nums[i]);

      i++;
    }

    return false;
  }
};

int main() {
  Solution sol;

  // vector<int> nums = {1, 2, 3, 1};
  // int indexDiff = 3;
  // int valueDiff = 0;

  vector<int> nums = {1, 5, 9, 1, 5, 9};
  int indexDiff = 2;
  int valueDiff = 3;

  printf("Contains Nearby Almost Duplicate: %d\n",
         sol.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff));
}
