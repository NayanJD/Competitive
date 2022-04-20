#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);

        for(int i = 0; i < length; i++){
            arr[i] = 0;
        }

        int n = updates.size();

        for(int i = 0; i < n; i++){
            arr[updates[i][0]] += updates[i][2];
            if(updates[i][1] < length - 1){
                arr[updates[i][1] + 1] -= updates[i][2];
            }
        }

        // printVector(arr);

        int sum = 0;
        for(int i = 0; i < length; i++){
            arr[i] += sum;
            sum = arr[i];
        }

        return arr;
    }

    void printVector(vector<int> arr){
        for(int i = 0; i < arr.size(); i++){
            printf("%d, ", arr[i]);
        }

        printf("\n");
    }
};


int main(){

    Solution sol;

    // vector<vector<int>> t1 = {{1,3,2},{2,4,3},{0,2,-2}};
    vector<vector<int>> t1 = {{2,4,6},{5,6,8},{1,9,-4}};

    sol.printVector(sol.getModifiedArray(10, t1));

    return 0;
}