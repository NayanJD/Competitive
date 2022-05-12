#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int largest = -1;
        for(int item: piles){
            if(largest < item){
                largest = item;
            }
        }

        int lo = 1, hi = largest;

        while(lo < hi){
            printf("lo: %d, hi: %d\n", lo, hi);

            int m = (lo + hi) / 2;

            // printf("isValidRate(piles, %d, h): %d\n", m, isValidRate(piles, m, h));

            if(isValidRate(piles, m, h)){
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }

        if(isValidRate(piles, lo, h)){
            return lo;
        } else {
            return lo + 1;
        }
    }

    bool isValidRate(vector<int>& piles, int k, int h) {
        int totalHours = 0;

        int n = piles.size();

        for(int i = 0; i < n; i++){
            totalHours += (int)ceil((double)piles[i] / k);
        }

        // printf("totalHours: %d\n", totalHours);

        return totalHours <= h;
    }
};

int main(){

    // vector<int> t1 = {3,6,7,11};
    // int h = 8;

    // vector<int> t1 = {30,11,23,4,20};
    // int h = 5;

    // vector<int> t1 = {30,11,23,4,20};
    // int h = 6;

    vector<int> t1 = {1000000000};
    int h = 2;

    Solution sol;

    printf("result: %d\n", sol.minEatingSpeed(t1, h));

    return 0;
}