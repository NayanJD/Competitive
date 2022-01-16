#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitBaskets;

        int maxCount = 0;
        int currCount = 0;
        int continuousVal = -1;
        int continuousCount = 0;
        for(int i = 0; i < fruits.size(); i++){

            if(fruitBaskets.size() < 2) {
                currCount++;
                fruitBaskets[fruits[i]] = i;
            } else if(fruitBaskets.find(fruits[i]) != fruitBaskets.end()){
                currCount++;
                fruitBaskets[fruits[i]] = i;
            } else {
                currCount = continuousCount + 1;
                int smallestIndex = 100001;
                int valToBeErased = -1;
                for(auto basket: fruitBaskets){
                    if(basket.second < smallestIndex){
                        smallestIndex = basket.second;
                        valToBeErased = basket.first;
                    }
                }
                fruitBaskets.erase(valToBeErased);
                fruitBaskets[fruits[i]] = i;
            }

            if (fruits[i] != continuousVal){
                continuousVal = fruits[i];
                continuousCount = 1;
            } else {
                continuousCount++;
            }

            // for(auto basket: fruitBaskets){
            //     cout << basket.first << ":" << basket.second << ", ";
            // }

            // cout << endl;

            if (currCount > maxCount) {
                maxCount = currCount;
            }
        }

        return maxCount;
    }
};

int main() {
    Solution sol;
    vector<int> vect{ 0,1,6,6,4,4,6 };
    vector<int> vect1{0,1,2,2};

    cout << sol.totalFruit(vect) << endl;
    cout << sol.totalFruit(vect1);
}