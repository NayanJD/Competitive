#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> v(10);

    for(int i = 0; i < 12; i++){
        printf("%d, ",v[i]);
    }
    return 0;
}