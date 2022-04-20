#include<iostream>
#include<vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int strokes = 0;
    int n = A.size();

    for(int i = 0; i < n; i++){
        if(i == 0){
            strokes = A[i];
        } else {
            if(A[i] > A[i - 1]){
                strokes += A[i] - A[ i - 1];
                strokes = min(strokes, 1000000000);
            }
        }
    }

    return strokes;
}

int main() {

    // vector<int> t1 = {1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};
    // vector<int> t1 = {5, 8};
    vector<int> t1 = {1, 1, 1, 1};



    printf("%d", solution(t1));

    return 0;
}