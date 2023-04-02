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
        int max_len  = 0;
        int start =0;
        if(n<2)return s;
        for(int i=1;i<n;i++){
            int left = i-1;
            int right  = i+1;

            while(left>=0 && s[i]==s[left]){
                left--;
            }
            while(right<n && s[i]==s[right]){
                right++;
            }
            while(left>=0 && right<n && s[right]==s[left]){
                left--;
                right++;
            }
            int len = right-left-1;
            if(len>max_len){
                max_len  =len;
                start = left+1;
            }
        }
    return s.substr(start,max_len);
    }
};

int main() {
    string t1 = "aaaabbaaaa";

    Solution sol;

    printf("longest palindrom string: %s\n", sol.longestPalindrome(t1).c_str());

    return 0;
}
