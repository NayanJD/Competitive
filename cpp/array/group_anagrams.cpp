#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> resultMap;

        string tmp;
        for(string str: strs){
            tmp = str;

            sort(tmp.begin(), tmp.end());

            if(resultMap.find(tmp) != resultMap.end()){
                resultMap[tmp].push_back(str);
            } else {
                resultMap[tmp] = {str};
            }
        }

        vector<vector<string>> result;

        for(auto mapPair: resultMap){
            result.push_back(mapPair.second);
        }

        return result;
    }
};

int main(){

    Solution sol;

    // vector<string> t1 = {"eat","tea","tan","ate","nat","bat"};
    // vector<string> t1 = {"a"};
    vector<string> t1 = {""};



    vector<vector<string>> ans = sol.groupAnagrams(t1);

    printf("[");

    for(auto i: ans){
        printf("[");
        for(auto j: i){
            printf("%s, ", j.c_str());
        }
        printf("]");
    }

    printf("]");
    return 0;
}