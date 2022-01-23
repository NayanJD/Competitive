// https://leetcode.com/problems/container-with-most-water/
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1


// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:

    // O(Nlog(N))
    // int maxArea(vector<int>& height) {
    //     map<int, pair<int, int>> indexMap;
    //     pair<int, int> defaultStat;
    //     defaultStat.first = 100001;
    //     defaultStat.second = -1;

    //     int n = height.size();

    //     for(int i = 0; i < n; i++) {
    //         if(indexMap.find(height[i]) == indexMap.end()) {
    //             indexMap[height[i]] = make_pair(100001, -1);
    //         }
    //     }

    //     for(int i = 0; i < n; i++) {
    //         auto stat = indexMap[height[i]];

    //         if(i < stat.first) {
    //             stat.first = i;
    //         }

    //         if(i > stat.second) {
    //             stat.second = i;
    //         }

    //         indexMap[height[i]] = stat;
    //     }

    //     auto lastEle = indexMap.rbegin();
    //     int smallestIndex = (*lastEle).second.first, largestIndex = (*lastEle).second.second;
    //     int maxVolume = (*lastEle).first * abs(largestIndex - smallestIndex);
    //     int maxWidth, heightVal;
    //     pair<int, int> valPair;
    //     for(auto i = ++indexMap.rbegin(); i != indexMap.rend(); i++) {
    //         heightVal = (*i).first;
    //         valPair = (*i).second;
            
    //         maxWidth = max(abs(largestIndex - valPair.first), abs(smallestIndex - valPair.second));
    //         maxVolume = max(maxVolume, heightVal * maxWidth);
    //         maxVolume = max(maxVolume, heightVal * abs(valPair.second - valPair.first));

    //         smallestIndex = min(smallestIndex, valPair.first);
    //         largestIndex = max(largestIndex, valPair.second);
    //     }

    //     return maxVolume;
    // }

    // O(N)
    int maxArea(vector<int>& height) {
        int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }



};

int main() {
    Solution s;

    vector<int> t1 = {1,8,6,2,5,4,8,3,7};
    vector<int> t2 = {1,1};
    vector<int> t3 = {1,2,4,3};

    cout << s.maxArea(t3);
}