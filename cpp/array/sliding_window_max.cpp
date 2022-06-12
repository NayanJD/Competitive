#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<short int> window;

        int n = nums.size();
        vector<int> result = {};
        // window.push_back(nums[0]);


        int i = 0, j = 0;

        while (j < n) {
            if(j - i < k - 1){

                // printf("window.back(): %d\n", window.back());
                // window.pop_back();

                while(window.size() != 0 && nums[j] > window.back()){
                    window.pop_back();
                }

                window.push_back(nums[j]);

                // printf("window: ");
                // for(int item: window){
                //     printf("%d, ", item);
                // }

                // printf("\n");

                j++;
            } else {

                // printf("window.front(): %d", window.back());
                while(window.size() != 0 && nums[j] > window.back()){
                    window.pop_back();
                }

                window.push_back(nums[j]);

                // printf("2nd window: ");
                
                // for(int item: window){
                //     printf("%d, ", item);
                // }

                // printf("\n");

                result.push_back(window.front());

                if(nums[i] == window.front()){
                    window.pop_front();
                }

                j++;
                i++;
            }
        }

        return result;
    }
};

int main() {
    vector<int> t1 = {1,3,-1,-3,5,3,6,7};
    int k = 4;

    // vector<int> t1 = {1};
    // int k = 1;

    Solution sol;

    auto result = sol.maxSlidingWindow(t1, k);

    for(int item: result){
        printf("%d, ", item);
    }

    return 0;
}