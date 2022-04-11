#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int val = *digits.rbegin();

        *digits.rbegin() = (val + 1) % 10;
        int carry = (val + 1) / 10;


        for(auto i = digits.rbegin() + 1; i != digits.rend(); i++){
            int val = *i;

            *i = (carry + val) % 10;
            carry = (val + carry) / 10;
        }

        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }

    void printPlusOne(vector<int> digits){
        for(int i = 0; i <digits.size(); i++){
            printf("%d", digits[i]);
        }
        printf("\n");
    }
};

int main() {

    Solution sol;

    vector<int> t1 = {4,3,2,1};

    sol.printPlusOne(sol.plusOne(t1));

    return 0;
}