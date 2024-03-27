// https://leetcode.com/problems/maximum-gap/description/
//
// 164. Maximum gap
//
// Given an integer array nums, return the maximum difference between two
// successive elements in its sorted form. If the array contains less than two
// elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra
// space.
//
//
//
// Example 1:
//
// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9)
// has the maximum difference 3. Example 2:
//
// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
//
// Constraints:
//
// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

struct Bucket {
  int minElement{numeric_limits<int>::max()};
  int maxElement{numeric_limits<int>::min()};
  bool isUsed{false};
};

class Solution {
public:
  int maximumGap(vector<int> &nums) {

    int n = nums.size();

    if (n == 1) {
      return 0;
    }

    int maxElement = *max_element(nums.begin(), nums.end());

    int minElement = *min_element(nums.begin(), nums.end());

    int b = ceil(((double)maxElement - minElement) / (n - 1));

    if (b == 0) {
      return 0;
    }

    // int k = ceil(((double)maxElement - minElement) / b);

    int k = ((maxElement - minElement) / b) + 1;

    log("k = %d, b = %d\n", k, b);

    vector<Bucket> buckets(k);

    int bucketIndex;

    for (int i = 0; i < n; i++) {
      bucketIndex = (nums[i] - minElement) / b;

      log("bucketIndex = %d\n", bucketIndex);

      buckets[bucketIndex].minElement =
          min(buckets[bucketIndex].minElement, nums[i]);

      buckets[bucketIndex].maxElement =
          max(buckets[bucketIndex].maxElement, nums[i]);

      buckets[bucketIndex].isUsed = true;
    }

    int maxGap{b};

    Bucket *prevBucket = nullptr;

    for (int i = 0; i < k; i++) {
      if (!buckets[i].isUsed) {
        continue;
      }

      if (prevBucket == nullptr) {
        prevBucket = &buckets[i];
      } else {
        maxGap = max(maxGap, buckets[i].minElement - prevBucket->maxElement);
        prevBucket = &buckets[i];
      }
    }

    return maxGap;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {3, 6, 9, 1};

  // vector<int> nums = {1, 1, 1, 1};

  log("Maximum gap between elements is: %d\n", sol.maximumGap(nums));
}
