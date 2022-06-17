#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currCount = 1;

        int prev = nums[0];

        int n = nums.size();

        int i = 0, j = 1;

        while(j < n){
            if(nums[j] == prev) {
                if(currCount < 2){
                    i++;
                    currCount++;
                }
            } else {
                i++;
                currCount = 1;
                prev = nums[j];
            }

            nums[i] = nums[j];
            
            j++;
        }

        int remaining = n - i - 1;
        while(remaining--){
            nums.pop_back();
        }

        return nums.size();
    }
};

int main() {
    Solution sol;

    vector<int> t = {0,0,1,1,1,1,2,2,2,2,3,3};

    int newSize = sol.removeDuplicates(t);

    printf("Size: %d\n", newSize);

    for(int num: t){
        printf("%d, ", num);
    }
    return 0;
}