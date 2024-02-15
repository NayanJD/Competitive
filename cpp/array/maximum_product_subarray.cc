// https://leetcode.com/problems/maximum-product-subarray
// 152. Maximum Product Subarray
//
// Given an integer array nums, find a
// subarray
//  that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// Constraints:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
// integer.

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//   int maxProduct(vector<int> &nums) {

//     if (nums.size() == 1) {
//       return nums[0];
//     }

//     nums.push_back(0);

//     int i{}, j{}, currentProduct{1}, maxProduct{-__INT_MAX__};
//     int n = nums.size();

//     while (i < n) {
//       if (nums[i] == 0 && currentProduct < 0) {

//         currentProduct = 1;
//         while (nums[j++] > 0) {
//         }

//         while (nums[j] != 0) {
//           currentProduct *= nums[j];
//           maxProduct = max(maxProduct, currentProduct);
//           j++;
//         }
//       }

//       currentProduct *= nums[i];
//       maxProduct = max(maxProduct, currentProduct);

//       if (currentProduct == 0) {
//         currentProduct = 1;
//         j = i + 1;
//       }

//       i++;
//     }

//     return maxProduct;
//   }
// };

class Solution {
public:
  int maxProduct(vector<int> nums) {
    if (nums.size() == 0)
      return 0;

    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int result = max_so_far;

    for (int i = 1; i < nums.size(); i++) {
      int curr = nums[i];
      int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
      min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

      max_so_far = temp_max;

      result = max(max_so_far, result);
    }

    return result;
  }
};

int main() {
  Solution sol;

  // vector<int> nums = {2, 3, -2, 4};

  vector<int> nums = {2, 3, -2, 5, -1, 2, 3, -1, 2, 3, 0, 10};

  // vector<int> nums = {-2};

  // vector<int> nums = {1, 0, -1, 2, 3, -5, -2};

  // vector<int> nums = {-2, 0, -1};

  // vector<int> nums = {3, -1, 4};

  printf("%d\n", sol.maxProduct(nums));
}
