#include<iostream>
#include<vector>

using namespace std;
    
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();

        if(s == t){
            return false;
        }

        if(n == m){
            for(int i = 0; i < n; i++){
                string newStr = s.substr(0, i) + t[i] + s.substr(i + 1, n - i - 1);

                if(newStr == t){
                    return true;
                }
            }

            return false;
        } else if (n == m - 1){
            for(int i = 0; i < m; i++){
                string newStr = s.substr(0, i) + t[i] + s.substr(i, n - i);

                if(newStr == t){
                    return true;
                }
            }

            return false;
        } else if (n - 1 == m){
            for(int i = 0; i < n; i++){
                string newStr = s.substr(0, i) + s.substr(i + 1, n - i - 1);

                if(newStr == t){
                    return true;
                }
            }

            return false;
        } else {
            return false;
        }
    }
};

int main() {

    Solution sol;

    string source = "";
    string target = "";

    printf("isOneEditDistance: %d", sol.isOneEditDistance(source ,target));

    return 0;
}