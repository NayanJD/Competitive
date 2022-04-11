// https://leetcode.com/problems/minimum-window-substring/
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.


// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?



#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> count, currCount;

        for(int i = 0; i < t.size(); i++){
            count[t[i]] = 0;
            currCount[t[i]] = 0;
        }

        for(int i = 0; i < t.size(); i++){
            count[t[i]]++;
        }

        int currSize = 0;
        int minWindowSize = 100001;
        int start = 0;

        for(int i = 0, j = 0; j < s.size();){
            // printf("i: %d, j: %d\n", i , j);

            if(count.find(s[j]) != count.end()){
                    
                currCount[s[j]]++;  

                if(currCount[s[j]] <= count[s[j]]){
                    currSize++;
                }
            }

            // printf("currSize: %d\n", currSize);

            while(currSize == t.size()){

                if(j - i + 1 < minWindowSize){
                    minWindowSize = j - i + 1;
                    start = i;
                }

                if(count.find(s[i]) != count.end()){

                    currCount[s[i]]--;

                    if(currCount[s[i]] < count[s[i]]){
                        currSize--;
                    }
                }

                i++;
            }

            j++;   
        }

        if(minWindowSize == 100001) {
            return "";
        } else {
            return s.substr(start, minWindowSize);
        }
    }
};

int main(){

    Solution sol;

    // cout << "Result: " << sol.minWindow("ADOBECODEBANC", "ABC");
    cout << "Result: " << sol.minWindow("a", "aa");


    return 0;
}