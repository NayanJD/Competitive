// https://leetcode.com/problems/count-primes/
// Given an integer n, return the number of prime numbers that are strictly less than n.
// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Constraints:

// 0 <= n <= 5 * 106

#include <iostream>
#include <unordered_set>
#include <set>


using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) {
            return 0;
        } else {
            int primes[n];
            
            for(int i = 2; i < n ; i++){
                primes[i] = i;
            }

            for(int i = 2; i < n ; i++){

                if(primes[i] != 0){
                    int val = i;
                    int j = 2;
                    
                    while(i * j < n){
                        primes[i * j++] = 0;
                    }
                }
                
            }

            int count = 0;
            for(int i = 2; i < n; i++){
                if(primes[i] != 0){
                    count++;
                }
            }
            return count;
        }
    }
};


int main (){
    Solution sol;

    printf("%d\n", sol.countPrimes(5000000));
}