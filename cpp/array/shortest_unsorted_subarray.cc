// https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// 581. Shortest Unsorted Continuous Subarray
//
//
// Given an integer array nums, you need to find one continuous subarray such
// that if you only sort this subarray in non-decreasing order, then the whole
// array will be sorted in non-decreasing order.

/* Return the shortest such subarray and output its length. */

/* Example 1: */

/* Input: nums = [2,6,4,8,10,9,15] */
/* Output: 5 */
/* Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
 * whole array sorted in ascending order. */
/* Example 2: */

/* Input: nums = [1,2,3,4] */
/* Output: 0 */
/* Example 3: */

/* Input: nums = [1] */
/* Output: 0 */

/* Constraints: */

/* 1 <= nums.length <= 104 */
/* -105 <= nums[i] <= 105 */

/* Follow up: Can you solve it in O(n) time complexity? */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int n = nums.size();
    int firstUnsortedIndex = n + 1, lastUnsortedIndex = n;

    vector<int> monotonicStack;

    for (int i = 0; i < n; i++) {
      while (!monotonicStack.empty() && nums[monotonicStack.back()] > nums[i]) {
        firstUnsortedIndex = min(firstUnsortedIndex, monotonicStack.back());

        monotonicStack.pop_back();
      }

      monotonicStack.push_back(i);
    }

    monotonicStack.clear();

    for (int i = 0; i < n; i++) {
      if (!monotonicStack.empty() && nums[monotonicStack.back()] > nums[i]) {
        lastUnsortedIndex = i;
      } else {
        monotonicStack.push_back(i);
      }
    }

    return lastUnsortedIndex - firstUnsortedIndex + 1;
  }
};

int main() {
  Solution sol;

  /* vector<int> nums = {2, 6, 4, 8, 10, 9, 15}; */
  vector<int> nums = {1, 2, 3, 4};
  /* vector<int> nums = {1}; */

  printf("Shortest Unsorted Continuous Subarray length: %d\n",
         sol.findUnsortedSubarray(nums));
}
