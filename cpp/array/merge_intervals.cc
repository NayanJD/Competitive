// https://leetcode.com/explore/interview/card/amazon/79/sorting-and-searching/2993/
// 
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// 
//  
// 
// Example 1:
// 
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:
// 
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//  
// 
// Constraints:
// 
// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104


#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool compareInterval(vector<int> i1, vector<int> i2)
{
    return (i1[0] < i2[0]);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> result;
       
       sort(intervals.begin(), intervals.end(), compareInterval);
       
       map<int,int> mergedIntervals;

       for(auto interval: intervals){
           auto nextLargest = mergedIntervals.lower_bound(interval[0]);

           if(nextLargest == mergedIntervals.end()){
               mergedIntervals[interval[1]] = interval[0];
           } else {
               int currFirst = nextLargest->first;
               int currSecond = nextLargest->second;

               if(currFirst < interval[1]){
                   mergedIntervals.erase(nextLargest);
                   mergedIntervals[interval[1]] = currSecond;

               }
           }
       }
        
       for(auto ele: mergedIntervals){
            result.push_back({ele.second, ele.first});
       }

       return result;
    }
};

void print2D(vector<vector<int>> &arr) {
    for(auto row: arr){
        for(auto ele: row){
            printf("%d,", ele);
        }
        printf("\n");
    }

    printf("\n");
}

int main(){
    
    Solution sol;

    vector<vector<int>> t1 = {{1,3},{2,18},{8,10},{15,18}};
    
    auto result = sol.merge(t1);
    print2D(result);


    vector<vector<int>> t2 = {{1,4},{4,5}};
    
    result = sol.merge(t2);
    print2D(result);

}
