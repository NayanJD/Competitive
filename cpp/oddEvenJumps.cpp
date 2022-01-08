// You are given an integer array arr. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not the indices.

// You may jump forward from index i to index j (with i < j) in the following way:

// During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that arr[i] <= arr[j] and arr[j] is the smallest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
// During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that arr[i] >= arr[j] and arr[j] is the largest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
// It may be the case that for some index i, there are no legal jumps.
// A starting index is good if, starting from that index, you can reach the end of the array (index arr.length - 1) by jumping some number of times (possibly 0 or more than once).

// Return the number of good starting indices.

// https://leetcode.com/explore/interview/card/google/67/sql-2/3045/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> evenPossibleMap;
        unordered_map<int, int> oddPossibleMap;
        set<int> sortedSet;

        evenPossibleMap[arr[n - 1]] = 1;
        oddPossibleMap[arr[n - 1]] = 1;
        sortedSet.insert(arr[n - 1]);

        int count = 1;
        for(int i = n - 2; i >= 0; i--) {
            // cout << "For " << arr[i] << "\n";
            // cout << arr[i] << ",";
            if(sortedSet.find(arr[i]) != sortedSet.end()) {
                // cout << "Found element\n";
                int temp = evenPossibleMap[arr[i]];
                evenPossibleMap[arr[i]] = oddPossibleMap[arr[i]];
                oddPossibleMap[arr[i]] = temp;
            } else {
                if (sortedSet.lower_bound(arr[i]) != sortedSet.begin()) {
                    // cout << "lower_bound " << *(--sortedSet.lower_bound(arr[i])) << endl;

                    int lowerBoundVal = *(--sortedSet.lower_bound(arr[i]));
                    evenPossibleMap[arr[i]] = oddPossibleMap[lowerBoundVal];
                } else {
                    // cout << "No lower_bound" << endl;
                    evenPossibleMap[arr[i]] = 0;
                }

                if (sortedSet.upper_bound(arr[i]) != sortedSet.end()) {
                    // cout << "upper_bound " << *sortedSet.upper_bound(arr[i]) << endl;
                    int upperBoundVal = *sortedSet.lower_bound(arr[i]);
                    oddPossibleMap[arr[i]] = evenPossibleMap[upperBoundVal];
                } else {
                    // cout << "No upper_bound" << endl;
                    oddPossibleMap[arr[i]] = 0;
                }
            }

            // cout << "\noddPossibleMap[arr[i]] " << oddPossibleMap[arr[i]] << endl;
            count += oddPossibleMap[arr[i]];

            sortedSet.insert(arr[i]);
            // for(int i: sortedSet){
            //     cout << i << ",";
            // }
            // cout << endl;

            
        }


        // for(auto itr = oddPossibleMap.begin(); itr != oddPossibleMap.end(); itr ++) {
        //     cout << itr->second << ",";
        //     if(itr->second){
        //         count++;
        //     }
        // }
        // cout << endl;
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> vect{ 10,13,12,14,15 };
    vector<int> vect2{ 2,3,1,1,4 };

    cout << sol.oddEvenJumps(vect) << endl << endl;
    cout << sol.oddEvenJumps(vect2);
}