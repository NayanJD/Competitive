#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int b = k;
        string upperCased = "";

        int n = s.size();
        int alphaCount = 0;
        for(int i = n -1; i >= 0; i--){
            if(s[i] != '-'){
                alphaCount++;
            }
        }
        // cout<< (float) alphaCount / k - 1 << endl;
        int resultSize = (int)(ceil(((float) alphaCount) / k)) - 1 + alphaCount + 1;

        if(resultSize == 0) {
            return "";
        }
        // cout << "resultSize + alphaCount " << resultSize + alphaCount << endl;
        char resultArr[resultSize];
        
        int j = resultSize - 2;
        for(int i = n - 1; i >= 0; i--) {
                
            if (s[i] != '-'){
                // cout << "j " << j << endl;
                // cout << upperCased << endl;
                if(b != 0){
                    resultArr[j] = toupper(s[i]);
                } else {
                    b = k;
                    resultArr[j] = '-';
                    resultArr[--j] = toupper(s[i]);
                    // cout << "reduced j to " << j << endl;
                }

                j--;
                b--;
            }
        }

        resultArr[resultSize - 1] = '\0';

        // for(auto c: resultArr){
        //     cout << c;
        // }
        // cout << endl;
        string result(resultArr);
        // cout << endl;
        return result;
    }
};

int main() {
    Solution s;

    cout << "licenseKeyFormatting " <<  s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
    cout << "licenseKeyFormatting " << s.licenseKeyFormatting("2-5g-3-J", 2);

}