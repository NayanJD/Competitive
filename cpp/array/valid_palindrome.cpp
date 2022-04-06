#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        return isValidPalindrome(s, 0, s.size() - 1, true);
    }

    bool isValidPalindrome(string s, int i, int j, bool canAllowSkip){

        while(i < j){
            if(s[i] != s[j]){
                if(canAllowSkip){
                    return isValidPalindrome(s, i, j - 1, false) || isValidPalindrome(s, i + 1, j, false);
                } else {
                    return false;
                }
            }

            i++;
            j--;
        }

        return true;
    }
};

int main() {
    string t2 = "deeee";

    Solution sol;

    printf("Result: %d", sol.validPalindrome(t2));

    return 0;
}