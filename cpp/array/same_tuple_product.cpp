#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> countMap;

        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(countMap.find(nums[i] * nums[j]) != countMap.end()) {
                    countMap[nums[i] * nums[j]]++;
                } else {
                    countMap[nums[i] * nums[j]] = 1;
                }
            }
        }

        int result = 0;
        for(auto kv: countMap){
            int count = kv.second;
            printf("%d: %d: %d\n", kv.first, kv.second, count * (count - 1) / 2 * 8);

            result += count * (count - 1) / 2 * 8;
        }

        return result;
    }
};


int main() {
    // vector<int> nums = {2,3,4,6};
    // vector<int> nums = {1,2,4,5,10};
    vector<int> nums = {2,3,4,6,8,12};


    Solution sol;

    printf("Result: %d", sol.tupleSameProduct(nums));

    return 0;
}

// 6 8 12 16 24 