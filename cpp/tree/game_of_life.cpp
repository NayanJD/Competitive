// https://leetcode.com/problems/game-of-life/
// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

// Example 1:
// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

// Example 2:
// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// Time: O(n) Space: O(n)
// Check out solution with same name in dp dir
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        unordered_set<int> visited;
        setNextStateDFS(board, 0, 0, visited);
    }

    int checkLifeAround(vector<vector<int>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();

        int livesAround = 0;

        if(i - 1 >= 0 && j - 1 >= 0){
            livesAround += board[i - 1][j - 1];
        }

        if(i - 1 >= 0){
            livesAround += board[i - 1][j];
        }

        if(i - 1 >= 0 && j + 1 < n){
            livesAround += board[i - 1][j + 1];
        }

        if(j + 1 < n){
            livesAround += board[i][j + 1];
        }

        if(i + 1 < m && j + 1 < n){
            livesAround += board[i + 1][j + 1];
        }

        if(i + 1 < m){
            livesAround += board[i + 1][j];
        }

        if(i + 1 < m && j - 1 >= 0){
            livesAround += board[i + 1][j - 1];
        }

        if(j - 1 >= 0){
            livesAround += board[i][j - 1];
        }

        printf("livesAround: %d\n", livesAround);

        if(livesAround < 2){
            return 0;
        } else if(livesAround == 3) {
            return 1;
        } else if(livesAround > 3){
            return 0;
        }

        return board[i][j];
    }

    void setNextStateDFS(vector<vector<int>>& board, int i, int j, unordered_set<int>& visited) {
        if(i < 0 || i >= board.size()){
            return;
        }

        if(j < 0 || j >= board[0].size()){
            return;
        }

        if(visited.find(i * board[0].size() + j) != visited.end()){
            return;
        }

        visited.insert(i * board[0].size() + j);

        int nextLife = checkLifeAround(board, i, j);

        printf("i: %d, j: %d, nextLife: %d\n", i, j, nextLife);

        setNextStateDFS(board, i - 1, j - 1, visited);
        setNextStateDFS(board, i - 1, j, visited);
        setNextStateDFS(board, i - 1, j + 1, visited);
        setNextStateDFS(board, i, j + 1, visited);
        setNextStateDFS(board, i + 1, j + 1, visited);
        setNextStateDFS(board, i + 1, j, visited);
        setNextStateDFS(board, i - 1, j - 1, visited);
        setNextStateDFS(board, i, j - 1, visited);

        board[i][j] = nextLife;

        return;

    }

    void printBoard(vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();
        
        printf("[");
        for(int i = 0; i < m; i++){
            printf("[");
            for(int j = 0; j < n; j++){
                printf("%d", board[i][j]);

                if(j < n-1){
                    printf(",");
                }
            }
            printf("]");
        }
    }
};

int main(){

    // vector<vector<int>> t1 = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    vector<vector<int>> t1 = {{1,1},{1,0}};


    Solution sol;

    sol.gameOfLife(t1);

    sol.printBoard(t1);

}