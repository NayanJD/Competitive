#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int i = 0, j = nums.size() - 1, mid;

    while (i != j) {
      if (nums[i] < nums[j]) {
        return nums[i];
      }

      mid = (i + j) / 2;

      if (nums[mid] <= nums[i] && nums[mid] < nums[j]) {
        j = mid;
      } else if (nums[mid] >= nums[i] && nums[mid] > nums[j]) {
        i = mid + 1;
      }
    }

    return nums[i];
  }
};

int main() {
  Solution sol;

  // vector<int> nums = {3, 4, 5, 1, 2};

  vector<int> nums = {11, 13, 15, 17};

  printf("Min: %d\n", sol.findMin(nums));
}
