// https://leetcode.com/problems/design-a-leaderboard/

// Design a Leaderboard class, which has 3 functions:

// addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
// top(K): Return the score sum of the top K players.
// reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
// Initially, the leaderboard is empty.

// Example 1:

// Input: 
// ["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
// [[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
// Output: 
// [null,null,null,null,null,null,73,null,null,null,141]

// Explanation: 
// Leaderboard leaderboard = new Leaderboard ();
// leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
// leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
// leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
// leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
// leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
// leaderboard.top(1);           // returns 73;
// leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
// leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
// leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
// leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
 

// Constraints:

// 1 <= playerId, K <= 10000
// It's guaranteed that K is less than or equal to the current number of players.
// 1 <= score <= 100
// There will be at most 1000 function calls.


#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<set>

using namespace std;

class Leaderboard {
    multiset<int> sortedScores;
    unordered_map<int, int> scoresById;

public:
    Leaderboard() {
    }
    
    void addScore(int playerId, int score) {
        auto itr = scoresById.find(playerId);

        if(itr != scoresById.end()){
            sortedScores.erase(sortedScores.find(itr->second));
            sortedScores.insert(itr->second + score);

            itr->second += score;
        } else {
            sortedScores.insert(score);
            scoresById.insert({playerId, score});
        }
    }
    
    int top(int K) {
        auto itr = sortedScores.rbegin();
        int i = 0;

        int sum = 0;
        while(i < K){

            sum+= *itr;

            itr++;
            i++;
        }

        return sum;
    }
    
    void reset(int playerId) {
        auto itr = scoresById.find(playerId);

        if(itr != scoresById.end()){
            sortedScores.erase(sortedScores.find(itr->second));

            scoresById.erase(playerId);
        }
    }

    void display(){
        for(auto itr = sortedScores.rbegin(); itr != sortedScores.rend(); itr++){
            printf("%d, ", *itr);
        }
        printf("\n");
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

int main() {

    // vector<string> t1Op = {"Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"};
    // vector<vector<int>> t1Args = {{},{1,73},{2,56},{3,39},{4,51},{5,4},{1},{1},{2},{2,51},{3}};

    vector<string> t1Op ={"Leaderboard","addScore","addScore","addScore","addScore","addScore","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","addScore","top","reset","reset","addScore","reset"};
    vector<vector<int>> t1Args = {{},{1,13},{2,93},{3,84},{4,6},{5,89},{6,31},{7,7},{8,1},{9,98},{10,42},{5},{1},{2},{3,76},{4,68},{1},{3},{4},{2,70},{2}};

    Leaderboard* obj = new Leaderboard();

    for(int i = 0; i < t1Op.size(); i++){
        if(t1Op[i] == "addScore"){
            obj->addScore(t1Args[i][0], t1Args[i][1]);
            printf("null\n");
        } else if (t1Op[i] == "top"){
            obj->display();
            printf("top: %d\n", t1Args[i][0]);
            printf("%d\n", obj->top(t1Args[i][0]));
        } else if (t1Op[i] == "reset"){
            printf("null\n");
            obj->reset(t1Args[i][0]);
        } else if (t1Op[i] == "Leaderboard"){
            printf("null\n");
        }
    }

    return 0;
}