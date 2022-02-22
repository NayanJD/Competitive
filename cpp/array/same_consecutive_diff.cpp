// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

// Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

// You may return the answer in any order.

 

// Example 1:

// Input: n = 3, k = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:

// Input: n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

// Constraints:

// 2 <= n <= 9
// 0 <= k <= 9

#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        unordered_set<int> result = {};
        
        for(int i = 1; i <= 9; i++){
            findNumbersRecursively(result, 0, i, 0, n , k);
        }

        vector<int> resultVector(result.begin(), result.end());

        return resultVector;
    }

    void findNumbersRecursively(unordered_set<int>& result, int currNumTillNow, int num, int level, int n, int k) {
        int currNum = currNumTillNow * 10 + num;
        if(level == n-1){
            result.insert(currNum);
        } else {
            if(num + k <=9){
                findNumbersRecursively(result, currNum, num + k, level + 1, n, k);
            }

            if(num - k >= 0){
                findNumbersRecursively(result, currNum, num - k, level + 1, n, k);
            }
        }
    }
};

int main() {
    Solution sol;


    vector<int> result = sol.numsSameConsecDiff(2, 0);
    
    for(auto item: result){
        printf("%d, ", item);

    }

    return 0;
}