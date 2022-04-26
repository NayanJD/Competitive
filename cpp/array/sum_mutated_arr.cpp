// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Sum of Mutated Array Closest to Target
//Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

// In case of a tie, return the minimum such integer.

// Notice that the answer is not neccesarilly a number from arr.

 

// Example 1:

// Input: arr = [4,9,3], target = 10
// Output: 3
// Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
// Example 2:

// Input: arr = [2,3,5], target = 10
// Output: 5
// Example 3:

// Input: arr = [60864,25176,27249,21296,20204], target = 56803
// Output: 11361

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int sum = 0, closestDiff = 100001, prevNum = -1, diffNum = 0;

        for(int i = 0; i < n; i++){
            
            // This is to round 0.5 to floor and 0.5 - 0.9 to ceil
            int restVal = ceil(abs((float)target - sum) / (n - i) - 0.5);
            
            if(restVal < arr[i] && restVal > prevNum){
                if(abs(target - sum - (n - i) * restVal) < closestDiff){
                    closestDiff = abs(target - sum - (n - i) * restVal);
                    diffNum = restVal;
                }
            }

            if(abs(target - sum - (n - i) * arr[i]) < closestDiff){
                closestDiff = abs(target - sum - (n - i) * arr[i]);
                diffNum = arr[i];
            }

            prevNum = arr[i];
            sum += arr[i];
        }

        return diffNum;
    }
};

int main(){

    Solution sol;
    // vector<int> t1 = {4,9,3};
    // vector<int> t1 = {2,3,5};
    // vector<int> t1 = {60864,25176,27249,21296,20204}; 
    vector<int> t1 = {1547,83230,57084,93444,70879}; //71237
    // vector<int> t1 = {2,2}; // 3



    printf("%d\n", sol.findBestValue(t1, 71237));
    return 0;
}