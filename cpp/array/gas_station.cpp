//https://leetcode.com/problems/minimize-max-distance-to-gas-station/
// You are given an integer array stations that represents the positions of the gas stations on the x-axis. You are also given an integer k.

// You should add k new gas stations. You can add the stations anywhere on the x-axis, and not necessarily on an integer position.

// Let penalty() be the maximum distance between adjacent gas stations after adding the k new stations.

// Return the smallest possible value of penalty(). Answers within 10-6 of the actual answer will be accepted.

// Example 1:

// Input: stations = [1,2,3,4,5,6,7,8,9,10], k = 9
// Output: 0.50000
// Example 2:

// Input: stations = [23,24,36,39,46,56,57,65,84,98], k = 1
// Output: 14.00000

// Constraints:

// 10 <= stations.length <= 2000
// 0 <= stations[i] <= 108
// stations is sorted in a strictly increasing order.
// 1 <= k <= 106

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

struct Reverse {

};

// O(N LogN) solution
// class Solution {
// public:
//     double minmaxGasDist(vector<int>& stations, int k) {
//         priority_queue<double> q;

//         int n = stations.size();

//         sort(stations.begin(), stations.end());

//         for(int i = 1; i < n; i++){
//             // printf("Inserting: %d\n", abs(stations[i] - stations[i-1]));

//             q.push(abs(stations[i] - stations[i - 1]));
//         }

//         // printf("size: %d\n", q.size());

//         printQueue(q);

//         while(k--){
//             double largest = q.top();
//             q.pop();

//             // printf("largest: %f\n", largest);

//             q.push(largest / 2);
//             q.push(largest / 2);

//             printQueue(q);
//         }

//         return q.top();
//     }

//     void printQueue(priority_queue<double> q){
//         while(q.size() != 0){
//             printf("%f, ", q.top());
//             q.pop();
//         }

//         printf("\n");
//     }
// };


class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        
        double lo = 0, hi = 10e8;

        while(lo < hi){
            double mid = (lo + hi) / 2;

            // printf("mid: %f, possible: %d\n", mid, possible(stations, k, mid));
            if(possible(stations, k, mid)){
                hi = mid - 10e-6;
            } else {
                lo = mid + 10e-6;
            }
        }

        if(possible(stations, k, lo)){
            return lo;
        } else {
            return lo + 10e-6;
        }
    }

    bool possible(vector<int>& stations, int k , double D){
        int n = stations.size();

        int total = 0;
        for(int i = 1; i < n; i++){
            total += floor((stations[i] - stations[i-1]) / D);
        }

        // printf("total: %d\n", total);

        return total <= k;
    }
};

int main (){
    
    vector<int> t1 = {1,2,3,4,5,6,7,8,9,10};
    int k = 9;

    // vector<int> t1 = {23,24,36,39,46,56,57,65,84,98};
    // int k = 1;

    // vector<int> t1 = {10,19,25,27,56,63,70,87,96,97};
    // int k = 3;

    Solution sol;

    printf("%f", sol.minmaxGasDist(t1, k));

    return 0;
}