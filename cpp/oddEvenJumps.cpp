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
#include <map>

using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int possibleJumps = 1;

        int n = arr.size();
        
        map<int, int> sortedIndices;
        sortedIndices[arr[n-1]] = n-1;

        unordered_map<int, pair<int,int>> possibleTillHere;
        possibleTillHere[n-1] = {1,1};

        for(int i = n-2; i >= 0; i--){
            pair<int,int> possibility;

            if(sortedIndices.lower_bound(arr[i]) == sortedIndices.end()) {
                possibility.first = 0;
            } else {
                possibility.first = possibleTillHere[(*sortedIndices.lower_bound(arr[i])).second].second; 
            }
            
            auto it = sortedIndices.lower_bound(arr[i]);

            
            if(it == sortedIndices.end()) {

                possibility.second = possibleTillHere[(*prev(it)).second].first;
            } else if((*it).first == arr[i]){
                possibility.second = possibleTillHere[(*it).second].first; 
            } else if (it != sortedIndices.begin()) {
                possibility.second = possibleTillHere[(*prev(it)).second].first;
            } else {
                possibility.second = 0;
            }

            possibleTillHere[i] = possibility;
            sortedIndices[arr[i]] = i;
            
            //printf("%d (%d, %d) ", i, possibility.first, possibility.second);

            if(possibility.first){
                possibleJumps++;
            }
        }

        printf("\n");

        return possibleJumps;
    }
};

int main() {
    Solution sol;

    vector<int> vect{ 10,13,12,14,15 };
    vector<int> vect2{ 2,3,1,1,4 };

    cout << sol.oddEvenJumps(vect) << endl << endl;
    cout << sol.oddEvenJumps(vect2);
}
