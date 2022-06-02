// https://leetcode.com/problems/edit-distance/
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        int dp[m+1][n+1], smallest;

        for(int i = 0; i < m + 1; i++){
            dp[i][0] = i;
        }

        for(int i = 0; i < n + 1; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(word2[i - 1] == word1[j - 1]){
                    smallest = dp[i-1][j-1];
                } else {
                    smallest = dp[i-1][j-1] + 1;
                }

                smallest = min(smallest, dp[i-1][j] + 1);
                smallest = min(smallest, dp[i][j-1] + 1);

                dp[i][j] = smallest;
            }
        }

        // for(int i = 0; i < m + 1; i++) {
        //     for(int j = 0; j < n + 1; j++){
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }

        return dp[m][n];
    }
};

int main() {
    // string word1 = "horse";
    // string word2 = "ros";

    string word1 = "intention";
    string word2 = "execution";

    Solution sol;

    printf("%d", sol.minDistance(word1, word2));
}