// https://leetcode.com/problems/next-permutation/
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]


#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int hasBroken = 0;

        for(int i = n - 2; i >= 0; i--){
            if (nums[i] < nums[i + 1]) {
                int nextBiggerIndex;

                for(int j = n - 1; j > i; j--){
                    if (nums[j] > nums[i]) {
                        nextBiggerIndex = j;
                        break;
                    }
                }

                swap(nums[i], nums[nextBiggerIndex]);

                for(int j = i + 1, k = n - 1; j < k; j++, k--){
                    swap(nums[j], nums[k]);
                }

                hasBroken = 1;
                break;
            }
        }   

        if(!hasBroken){
            for(int j = 0, k = n - 1; j < k; j++, k--){
                    swap(nums[j], nums[k]);
            }
        }

    }
};

int main() {
    Solution sol;

    vector<int> t1 = {1, 3, 4, 5, 2};

    sol.nextPermutation(t1);

    for(int num: t1){
        printf("%d, ", num);
    }
    return 0;
}