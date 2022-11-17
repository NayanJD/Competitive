// https://leetcode.com/problems/find-and-replace-pattern/

// Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

// Example 1:

// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
// Example 2:

// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int m = pattern.size();
        
        vector<string> result;
        for(string word: words){
            unordered_map<char, char> dict;

            bool hasMatched = true;
            // printf("For word: %s \n", word.c_str());

            for(int j = 0; j < m; j++) {
                if(dict.find(word[j]) == dict.end()) {
                    dict[word[j]] = pattern[j];
                }

                if(dict[word[j]] != pattern[j]) {
                    hasMatched = false;
                    break;
                }
            }

            dict.clear();
            for(int j = 0; j < m; j++) {
                if(dict.find(pattern[j]) == dict.end()) {
                    dict[pattern[j]] = word[j];
                }

                if(dict[pattern[j]] != word[j]) {
                    hasMatched = false;
                    break;
                }
            }

            if(hasMatched){
                result.push_back(word);
            }
        } 
        return result;
    }
};

int main() {

//  vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
//  string pattern = "abb";

 vector<string> words = {"ef","fq","ao","at","lx"};
 string pattern =   "ya";

 Solution sol;
 auto result = sol.findAndReplacePattern(words, pattern);
 
 printf("\n\n\n");

 for(int i = 0; i < result.size(); i++){
    printf("%s, ", result[i].c_str());
 }
}