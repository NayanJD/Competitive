//https://leetcode.com/explore/interview/card/google/59/array-and-strings/3052/
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int temp;
        for(int i = 0; i < (n / 2); i++) {
            for(int j = i; j < (n - i - 1); j++){

                temp = matrix[i][j];

                // top to left
                swap(temp, matrix[j][n - i - 1]);

                // left to bottom
                swap(matrix[n - i - 1][n - j - 1], temp);

                // bottom to left
                swap(temp, matrix[n - j - 1][i]);

                // left to top
                swap(temp, matrix[i][j]);
            }
        }
    }
};

void print2D(vector<vector<int>>& matrix){
    int n = matrix.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    vector<vector<int>> t1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> t2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    Solution sol;

    sol.rotate(t1);

    print2D(t1);

    return 0;
}