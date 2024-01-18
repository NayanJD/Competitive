// https://leetcode.com/problems/sort-array-by-moving-items-to-empty-space
//
// You are given an integer array nums of size n containing each element from 0
// to n - 1 (inclusive). Each of the elements from 1 to n - 1 represents an
// item, and the element 0 represents an empty space.
//
// In one operation, you can move any item to the empty space. nums is
// considered to be sorted if the numbers of all the items are in ascending
// order and the empty space is either at the beginning or at the end of the
// array.
//
// For example, if n = 4, nums is sorted if:
//
// nums = [0,1,2,3] or
// nums = [1,2,3,0]
//...and considered to be unsorted otherwise.
//
// Return the minimum number of operations needed to sort nums.
//
//
//
// Example 1:
//
// Input: nums = [4,2,0,3,1]
// Output: 3
// Explanation:
//- Move item 2 to the empty space. Now, nums = [4,0,2,3,1].
//- Move item 1 to the empty space. Now, nums = [4,1,2,3,0].
//- Move item 4 to the empty space. Now, nums = [0,1,2,3,4].
// It can be proven that 3 is the minimum number of operations needed.
// Example 2:
//
// Input: nums = [1,2,3,4,0]
// Output: 0
// Explanation: nums is already sorted so return 0.
// Example 3:
//
// Input: nums = [1,0,2,4,3]
// Output: 2
// Explanation:
//- Move item 2 to the empty space. Now, nums = [1,2,0,4,3].
//- Move item 3 to the empty space. Now, nums = [1,2,3,4,0].
// It can be proven that 2 is the minimum number of operations needed.
//
//
// Constraints:
//
// n == nums.length
// 2 <= n <= 105
// 0 <= nums[i] < n
// All the values of nums are unique.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int sortArray(vector<int> &nums) {
    unordered_map<int, int> unSortedIndexes;

    int n = nums.size();

    vector<int> numsCopy(nums.begin(), nums.end());

    /* printf("RightOps==========\n"); */

    int currentZeroIndex = n - 1;

    for (int i = 0; i < n; i++) {
      if (numsCopy[i] == 0) {
        currentZeroIndex = i;
        continue;
      }

      if (numsCopy[i] != i + 1) {
        unSortedIndexes[numsCopy[i]] = i;
      }
    }

    int unSortedCount = unSortedIndexes.size(), rightOps = 0, oldZeroIndex;

    while (unSortedCount != 0) {
      if (currentZeroIndex == n - 1) {
        /* int temp = numsCopy[*unSortedIndexes.begin()]; */
        /* numsCopy[*unSortedIndexes.begin()] = 0; */
        /* numsCopy[n - 1] = temp; */
        /* printf("Randomizing swap: %d and %d\n", n - 1, */
        /*        unSortedIndexes.begin()->second); */
        swap(numsCopy[unSortedIndexes.begin()->second], numsCopy[n - 1]);
        currentZeroIndex = unSortedIndexes.begin()->second;
        unSortedIndexes[numsCopy[n - 1]] = n - 1;
      } else {
        /* printf("Fixed swap: %d and %d\n", currentZeroIndex, */
        /*        unSortedIndexes[currentZeroIndex + 1]); */
        numsCopy[unSortedIndexes[currentZeroIndex + 1]] = 0;
        numsCopy[currentZeroIndex] = currentZeroIndex + 1;

        oldZeroIndex = currentZeroIndex;

        currentZeroIndex = unSortedIndexes[currentZeroIndex + 1];

        unSortedIndexes.erase(oldZeroIndex + 1);

        unSortedCount--;
      }

      rightOps++;
    }

    numsCopy.clear();
    numsCopy.insert(numsCopy.begin(), nums.begin(), nums.end());

    unSortedIndexes.clear();

    /* printf("LeftOps==========\n"); */

    currentZeroIndex = 0;

    for (int i = 0; i < n; i++) {
      if (numsCopy[i] == 0) {
        currentZeroIndex = i;
        continue;
      }

      if (numsCopy[i] != i) {
        unSortedIndexes[numsCopy[i]] = i;
      }
    }

    unSortedCount = unSortedIndexes.size();
    int leftOps = 0;

    while (unSortedCount != 0) {
      if (currentZeroIndex == 0) {
        /* int temp = numsCopy[*unSortedIndexes.begin()]; */
        /* numsCopy[*unSortedIndexes.begin()] = 0; */
        /* numsCopy[n - 1] = temp; */
        swap(numsCopy[unSortedIndexes.begin()->second], numsCopy[0]);
        currentZeroIndex = unSortedIndexes.begin()->second;
        unSortedIndexes[numsCopy[0]] = 0;
        /* printf("Randomizing swap: %d and %d\n", 0, */
        /*        unSortedIndexes.begin()->second); */
      } else {
        /* printf("Fixed swap: %d and %d\n", currentZeroIndex, */
        /*        unSortedIndexes[currentZeroIndex]); */
        numsCopy[unSortedIndexes[currentZeroIndex]] = 0;
        numsCopy[currentZeroIndex] = currentZeroIndex;

        oldZeroIndex = currentZeroIndex;

        currentZeroIndex = unSortedIndexes[currentZeroIndex];

        unSortedIndexes.erase(oldZeroIndex);

        unSortedCount--;
      }

      leftOps++;
    }

    return min(leftOps, rightOps);
  }
};

// class Solution {
// public:
// class UF{
// public:
//     vector<int> parent, size;
//     int _n;
//     UF (int n) : parent(n), size(n, 1), _n{n}{
//         iota(parent.begin(), parent.end(), 0);
//     }
//
//     int leader(int x){
//         return x == parent[x]? x : parent[x] = leader(parent[x]);
//     }
//
//     void unite(int x, int y){
//         x = leader(x);
//         y = leader(y);
//         if (x == y){
//             return;
//         }
//         if (size[y] > size[x]){
//             swap(x, y);
//         }
//         size[x] += size[y];
//         parent[y] = x;
//     }
//
//     int score(){
//         int ans = 0;
//         for (int i = 0; i < _n; ++i){
//             if (parent[i] == i && size[i] > 1){
//                 if (leader(0) != i){ // cond 3
//                     ++size[i];
//                     ++ans;
//                 }
//                 ans += size[i] - 1;
//             }
//         }
//         return ans;
//     }
// };
//
//     int sortArray(vector<int>& nums) {
//         int a = 0;
//         int b = 0;
//         int n = nums.size();
//         UF uf0(n);
//         UF uf1(n);
//
//         for (int i = 0; i < n; ++i){
//             uf0.unite(nums[i], nums[nums[i]]);
//         }
//         for (int i = 0; i < n; ++i){
//             uf1.unite(nums[i], nums[(nums[i] - 1 + n) % n]);
//         }
//
//         return min(uf0.score(), uf1.score());
//     }
// };

int main() {

  Solution sol;

  vector<int> nums = {4, 2, 0, 3, 1};

  /* vector<int> nums = {1, 2, 3, 4, 0}; */

  /* vector<int> nums = {1, 0, 2, 4, 3}; */

  /* vector<int> nums = {0, 1, 2, 3, 4}; */

  /* vector<int> nums = {4, 1, 2, 3, 0}; */

  /* vector<int> nums = {3, 2, 1, 6, 7, 4, 5, 0}; */

  printf("Minimum number of operations needed: %d\n", sol.sortArray(nums));
}
