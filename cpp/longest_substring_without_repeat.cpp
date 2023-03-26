// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Given a string s, find the length of the longest 
// substring
//  without repeating characters.
// 
//  
// 
// Example 1:
// 
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:
// 
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
// 
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//  
// 
// Constraints:
// 
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


void showLetters(unordered_map<char, int> letters) {
    for(auto letter: letters) {
        printf("%c ", letter.first);
    }
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int startingPoint = 0;
        int result = 0;

        unordered_map<char, int> letters;

        for(int i = 0; i < n; i++) {
            if(letters.find(s[i]) == letters.end()) {
                letters[s[i]] = i;
                
            } else {
                int idx = letters[s[i]];

                while(startingPoint <= idx) {
                    letters.erase(s[startingPoint]);
                    startingPoint++;
                }

                letters[s[i]]= i;
            }
            
            if(result < letters.size()) {
                result = letters.size();
            }

            //printf("i: %d, letters: ", i);
            //showLetters(letters);
            //printf("\n");
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << "abcabcbb " << sol.lengthOfLongestSubstring("abcabcbb") << endl; 
    cout << "bbbbb " << sol.lengthOfLongestSubstring("bbbbb") << endl; 
    cout << "pwwkew " << sol.lengthOfLongestSubstring("pwwkew") << endl; 
}   
