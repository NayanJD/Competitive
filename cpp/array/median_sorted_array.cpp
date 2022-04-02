#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return 0;
    }

    int posInSortedArray(vector<int>& nums, int low, int high, int item){
        if(low >= high){
            if(low >= item){
                return low;
            } else {
                return low + 1;
            }
        }

        int mid = (low + high) / 2;

        if(item == nums[mid] && item > nums[mid - 1]){
            return mid;
        } else if (item > nums[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }

        return posInSortedArray(nums, low, high, item);
    }
};


int main (){

    Solution sol;

    vector<int> t1 = {0,0,0,1,2,3,3};

    printf("Result: %d", sol.posInSortedArray(t1, 0, t1.size() - 1, 3));

    return 0;
}