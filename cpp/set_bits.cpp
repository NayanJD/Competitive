#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution{
    public:
        int getSetBits(vector<int>& arr){
            int n = arr.size();

            int count = 0;
            for(int i = 0; i < n; i++){
                int p = 0;


                while(arr[i] >= (int)pow(2, p)){
                    // printf("val %d and %d\n", arr[i], arr[i] & (int)pow(2,p));
                    if((arr[i] & (int)pow(2,p)) == (int)pow(2,p)){
                        count++;
                    }

                    p++;
                }   
            }

            return count;
        }
};


int main(){
    vector<int> t1 = {3};

    Solution sol;
    printf("%d", sol.getSetBits(t1));

    return 0;
}