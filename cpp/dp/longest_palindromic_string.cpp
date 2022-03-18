// https://leetcode.com/explore/interview/card/google/64/dynamic-programming-4/451/
// Given a string s, return the longest palindromic substring in s.
// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#include<iostream>

using namespace std;

class Solution {
public:
    // 0(n^2) solution
    string longestPalindrome(string s) {
        int n = s.size();

        bool dp[n][n];

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                dp[i][j] = true;
            }
        }

        int longestj = 0;
        int longestLength = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(dp[i-1][j+1] && s[i] == s[j]){
                    dp[i][j] = true;
                    if(i - j + 1 > longestLength){
                        longestj = j;
                        longestLength = i - j + 1;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }

        return s.substr(longestj, longestLength);

    }
};

int main() {
    string t1 = "a";

    Solution sol;

    printf("longest palindrom string: %s", sol.longestPalindrome(t1).c_str());

    return 0;
}