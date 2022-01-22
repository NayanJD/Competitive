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
    int maxArea(vector<int>& height) {
        map<int, pair<int, int>> indexMap;
        pair<int, int> defaultStat;
        defaultStat.first = 100001;
        defaultStat.second = -1;

        int n = height.size();

        for(int i = 0; i < n; i++) {
            if(indexMap.find(height[i]) == indexMap.end()) {
                indexMap[height[i]] = make_pair(100001, -1);
            }
        }

        for(int i = 0; i < n; i++) {
            auto stat = indexMap[height[i]];
            printf("i: %d stat.first: %d stat.second: %d\n", i, stat.first, stat.second);

            if(i < stat.first) {
                cout << "setting smallest\n";

                stat.first = i;
            }

            if(i > stat.second) {
                cout << "setting largest\n";
                stat.second = i;
            }

            printf("stat.first: %d stat.second: %d \n", stat.first, stat.second);
            indexMap[height[i]] = stat;
        }

        for(int i = 0; i < n; i++) {
            printf("height %d first: %d second: %d\n", height[i], indexMap[height[i]].first, indexMap[height[i]].second);
        }

        int smallestIndex = indexMap[height[n - 1]].first, largestIndex = indexMap[height[n - 1]].second;
        int maxVolume = -1;

        for(int i = n - 2; i >= 0; i--){
            cout << "smallestIndex: " << smallestIndex;
            cout << "largestIndex: " << largestIndex ;

            maxVolume = max(maxVolume, height[i] * abs(i - smallestIndex));
            maxVolume = max(maxVolume, height[i] * abs(i - largestIndex));

            smallestIndex = min(indexMap[height[i]].first, smallestIndex);
            largestIndex = max(indexMap[height[i]].second, largestIndex);

            cout << endl;
        }

        // for(auto i = indexMap.rbegin() + 1; i != indexMap.rend(); i++){
        //     cout << "smallestIndex: " << smallestIndex;
        //     cout << "largestIndex: " << largestIndex ;

        //     maxVolume = max(maxVolume, height[i] * abs(i - smallestIndex));
        //     maxVolume = max(maxVolume, height[i] * abs(i - largestIndex));

        //     smallestIndex = min(indexMap[height[i]].first, smallestIndex);
        //     largestIndex = max(indexMap[height[i]].second, largestIndex);

        //     cout << endl;
        // }

        return maxVolume;
    }
};

int main() {
    Solution s;

    vector<int> t1 = {1,8,6,2,5,4,8,3,7};

    cout << s.maxArea(t1);
}