#include<iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int pow(int n) {
        int num = 1;
        while(n > 0) {
            num *= 10;
            n--;
        }

        return num;
    }

    string multiply(string num1, string num2) {
        int num1_n = num1.size(), num2_n = num2.size();
        long long int num1_arr[23], num2_arr[23];

        for(int j = 0; j < 23; j++){
            num1_arr[j] = 0;
            num2_arr[j] = 0;
        }

        // num1_arr[0] = 999999999;

        // printf("teest store %lld\n", num1_arr[0]);

        int currNum = 0;
        int i = 0;
        auto itr = num1.rbegin();

        while(itr != num1.rend()) {
            if(i % 9 == 0 && i != 0){
                printf("Saving current num as %d in %d\n",currNum, i / 9 - 1);
                num1_arr[i / 9 - 1] = currNum;
                currNum = (*itr) - '0';
            } else {
                printf("pow %d\n", pow(i % 9) * ((*itr) - '0'));

                currNum += pow(i % 9) * ((*itr) - '0');
                printf("%d\n", currNum);
            }

            i++;
            itr++;
        }

        for(int j = 0; j < 23; j++){
            printf("%lld",num1_arr[j]);
        }


        return "";
    }

    string add(string num1, string num2){
        
        return "";
    } 
};

int main() {


    // printf("%d\n", INT_MAX);
    // printf("%lld\n\n", LONG_LONG_MAX);

    // long int x = 999999999;

    // long long int y = (long long int)x * x;

    // printf("%lld\n", y);

    // char c = '9';
    // printf("%d", c - '0');

    Solution sol;
    printf("%d\n", sol.pow(0 % 9));

    sol.multiply("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", "");

    return 0;
}   