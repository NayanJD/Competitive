#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {

    map<int, int> countLe;

    int longestLength = 1;
    for (int i = 0; i < nums.size(); i++) {
      auto itr = countLe.lower_bound(nums[i]);

      if (itr != countLe.begin()) {
        countLe[nums[i]] = prev(itr)->second + 1;
        longestLength = max(longestLength, countLe[nums[i]]);
      } else {
        countLe[nums[i]] = 1;
      }

      if (itr != countLe.end() && itr->first == nums[i]) {
        itr++;
      }
      auto end = itr;

      while (end != countLe.end() && end->second < countLe[nums[i]]) {
        end++;
      }

      countLe.erase(itr, end);
    }

    return longestLength;
  }
};

int main() {
  Solution sol;

  // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

  // vector<int> nums = {0, 1, 0, 3, 2, 3};

  vector<int> nums = {7, 7, 7, 7, 7, 7, 7};

  printf("Longest increasing subsequence length: %d\n", sol.lengthOfLIS(nums));
}
