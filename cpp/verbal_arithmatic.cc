#include<vector>
// https://leetcode.com/problems/verbal-arithmetic-puzzle/description/
//
// Given an equation, represented by words on the left side and the result on the right side.
//
//You need to check if the equation is solvable under the following rules:
//
//Each character is decoded as one digit (0 - 9).
//No two characters can map to the same digit.
//Each words[i] and result are decoded as one number without leading zeros.
//Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
//
// 
//
//Example 1:
//
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//
//Constraints:
//
//2 <= words.length <= 5
//1 <= words[i].length, result.length <= 7
//words[i], result contain only uppercase English letters.
//The number of different characters used in the expression is at most 10.

#include<iostream>
#include<cmath>

using namespace std;

bool compare(vector<int>& i1, vector<int>& i2)
{   
    int a = i1[0] < 0 ? -1 * i1[0] : i1[0];
    int b = i2[0] < 0 ? -1 * i2[0] : i2[0];

    return (b  < a);
}

class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        vector<int> leftCharCount(26, 0), leading(26,1);

        for(auto word: words){
            int p = 0;
            for(auto itr = word.end() - 1; itr >= word.begin(); itr--, p++) {
                //printf("%f \n", pow(10,p));
                leftCharCount[*itr % 65] += pow(10, p);

                if(itr == word.begin() && word.size() > 1) {
                    leading[*itr % 65] = 0;
                }
            }

        }

        //printf("\n");

        vector<int> rightCharCount(26, 0);
        
        int p = 0;
        for(auto itr = result.end() - 1; itr >= result.begin(); itr--, p++){
            //printf("%c %d\n", letter, letter % 65);
            rightCharCount[*itr % 65] += pow(10, p);
        }
        leading[result[0] % 65] = 0;

        for(int i = 0; i < 26; i++){
            if(leading[i] == 0){
                //printf("%c, ", i + 65);
            }
        }
        //printf("\n");

        int uniqueCount = 0;
        for(int i = 0; i < 26; i++){
            
            if(leftCharCount[i] || rightCharCount[i]){
                //printf("%c %d, ", i + 65, leftCharCount[i]);
                //printf("%c %d\n", i + 65, rightCharCount[i]);
                uniqueCount++;
            }

            leftCharCount[i] -= rightCharCount[i];
            rightCharCount[i] = 0;
            
            //printf("uniqueCount: %d\n", uniqueCount);
            if(uniqueCount > 10) {
                return false;
            }
        }

        //sort(leftCharCount.begin(), leftCharCount.end());

        vector<vector<int>> equation;
        
        for(int i = 0; i < 26; i++) {
            if(leftCharCount[i] == 0) continue;
            
            //printf("(%c, %d, %d), ", i + 65, leftCharCount[i], leading[i]);
            
            equation.push_back({leftCharCount[i],-1, leading[i]});
        }
        
        //printf("\n");
        //
        sort(equation.begin(), equation.end(),compare);

        vector<int> possibleValues(10, 1); 
        return isPossible(equation, possibleValues,0);
    }

    bool isPossible(vector<vector<int>>& equation, vector<int>&possibleValues, int level) {
        if(level == equation.size()) {
            int value = 0;
            
            for(int i = 0; i < equation.size(); i++){
                
                value += equation[i][0] * equation[i][1];
            } 
           
            
            return value == 0;
        }
        
        //int i = equation[level][2] ? 0: 1;

        for(int i = 0; i < 10; i++){
            if(possibleValues[i]) {
                if(i == 0 && equation[level][2] == 0) continue;

                equation[level][1] = i;
                possibleValues[i] = 0;
                if(isPossible(equation, possibleValues, level + 1)){
                    return true;
                }
                possibleValues[i] = 1;
            }
        }

        equation[level][1] = -1;
        return false;
    }
};

int main(){
    Solution sol;

    vector<string> words ={"SEND","MORE"};
    string result = "MONEY";

    printf("IsSolvable 0: %d\n", sol.isSolvable(words, result));

    vector<string> words1 ={"SIX","SEVEN","SEVEN"};
    string result1 = "TWENTY";

    printf("IsSolvable 1: %d\n", sol.isSolvable(words1, result1));

    vector<string> words2 ={"LEET","CODE"};
    string result2 = "POINT";

    printf("IsSolvable 2: %d\n", sol.isSolvable(words2, result2));

    vector<string> words3 ={"CBA","CBA","CBA","CBA","CBA"};
    string result3 = "EDD";

    printf("IsSolvable 3: %d\n", sol.isSolvable(words3, result3));

    vector<string> words4 ={"AB","CD","EF"};
    string result4 = "GHIJ";

    printf("IsSolvable 4: %d\n", sol.isSolvable(words3, result3));
}
