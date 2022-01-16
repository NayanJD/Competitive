#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto i = s.begin();
        auto j = s.begin();

        int maxLength = 0;
        unordered_map<char, int> isPresentMap;

        while(i != s.end()){
            if(isPresentMap.find(*i) != isPresentMap.end()) {
                while(j != i) {
                    if (*i == *j){
                        j++;
                        break;
                    }
                    isPresentMap.erase(*j);
                    j++;
                }
            }
            
            isPresentMap[*i] = 1;

            maxLength = max(maxLength, (int) isPresentMap.size());
            i++;
        }

        return maxLength;

    }
};

int main() {
    Solution sol;

    cout << "abcabcbb " << sol.lengthOfLongestSubstring("abcabcbb") << endl; 
    cout << "bbbbb " << sol.lengthOfLongestSubstring("bbbbb") << endl; 
    cout << "pwwkew " << sol.lengthOfLongestSubstring("pwwkew") << endl; 
}   