// Decode String
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        int n = s.length();

        string result = "";

        while(pos < n){
            if(isDigit(s[pos])){
                result += decodeStringRecur(s, pos);
            } else {
                result += s[pos];
            }
            pos++;
        }

        return result;
    }

    bool isDigit(char c){
        return c - '0' >= 0 && c - '0' < 10;
    }

    string decodeStringRecur(string s, int& pos) {
        char c = s[pos];


        string currStr = "";

        int n = 0;
        while(isDigit(s[pos])){
            n = n * 10 + s[pos] - '0';
            pos++;
        }

        // printf("%d\n", n);
        pos += 1;

        while(s[pos] != ']'){
            if(isDigit(s[pos])){
                currStr += decodeStringRecur(s, pos);
            } else {
                currStr += s[pos];
            }

            pos++;
        }

        string newStr = "";

        for(int i = 0; i < n; i++){
            newStr += currStr;
        }

        return newStr;
    }
};

int main() {
    Solution sol;

    // string t1 = "3[a]2[bc]";
    // string t1 = "3[a2[c]]";
    string t1 = "2[abc]3[cd]ef";
    // string t1 = "100[leetcode]";


    // printf("%s", sol.decodeString(t1));

    cout << sol.decodeString(t1);

    return 0;
}