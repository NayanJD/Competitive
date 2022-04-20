#include<iostream>
#include<vector>

using namespace std;

int solution(vector<int>& A, int X) {
    int N = A.size();
    if (N == 0) {
        return -1;
    }
    int l = 0;
    int r = N - 1;
    while (l < r) {
        // printf("l %d r %d", l, r);
        
        int m = (l + r) / 2;
        if (A[m] > X) {
            r = m - 1;
        } else {
            if(A[m] == X) return m;
            else
                l = m + 1;
        }
    }
    if (A[l] == X) {
        return l;
    }
    return -1;
}

int main() {

    vector<int> t1 = {1, 2, 5, 9, 9};

    printf("%d", solution(t1, 2));
    return 0;
}