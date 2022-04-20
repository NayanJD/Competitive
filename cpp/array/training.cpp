#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int getUnionLength(unordered_set<int> s1, unordered_set<int> s2){
    for(auto i = s1.begin(); i != s1.end(); i++){
        s2.erase(*i);
    }

    return s1.size() + s2.size();
}

int solution(vector<string> &E) {
    // write your code in C++14 (g++ 6.2.0)

    unordered_set<int> setArr[10];
    int n = E.size();

    string str;
    for(int i = 0; i < n; i++){
        int str_len = E[i].length();
        for(int j = 0; j < str_len; j++){
            char k = E[i][j];
            setArr[k - '0'].insert(i);

            if(setArr[k - '0'].size() == n){
                return n;
            }
        }
    }

    int maxPeople = 0;

    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            maxPeople = max(maxPeople, getUnionLength(setArr[i], setArr[j]));
        }
    }

    return maxPeople;

}

int main (){

    // vector<string> t1 = {"039", "4", "14", "32", "34", "7"};
    // vector<string> t1 = {"801234567", "180234567", "0", "189234567", "891234567", "98", "9"};
    // vector<string> t1 = {"5421", "245", "1452", "0345", "53", "354"};
    // vector<string> t1 = {"0", "1", "2", "3", "4", "5"};
    vector<string> t1 = {"0", "0", "0", "0", "0", "1"};

    printf("%d", solution(t1));
    return 0;
}