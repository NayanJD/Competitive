#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -10001, currSum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(currSum + nums[i] > nums[i]){
                currSum += nums[i];
            } else {
                currSum = nums[i];
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};

int main(){
    vector<int> t1 = {5,4,-1,7,8};

    Solution sol;

    printf("Max sum: %d", sol.maxSubArray(t1));

    return 0;
}