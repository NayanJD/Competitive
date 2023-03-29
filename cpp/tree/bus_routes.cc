// https://leetcode.com/problems/bus-routes/description/
// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
// 
// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
// 
//  
// 
// Example 1:
// 
// Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
// Output: 2
// Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
// Example 2:
// 
// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
// Output: -1
//  
// 
// Constraints:
// 
// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 105
// All the values of routes[i] are unique.
// sum(routes[i].length) <= 105
// 0 <= routes[i][j] < 106
// 0 <= source, target < 106


#include<vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       unordered_set<int> busesNotVisited;
       busesNotVisited.reserve(routes.size());

       for(int i = 0; i < routes.size(); i++){
           busesNotVisited.insert(i);
       }
       
       unordered_set<int> stopsVisited;

       vector<unordered_set<int>> routesSet;
        
       int n = routes.size();
       for(int i = 0; i < n; i++){
            unordered_set<int> currStops(routes[i].begin(), routes[i].end());
            routesSet.push_back(currStops);
       }

       queue<int> q;
       q.push(source);
       stopsVisited.insert(source);
        
       unordered_map<int, int> resultMap;
       resultMap[source] = 0;

       while(q.size() != 0) {

          int currStop = q.front();
          q.pop(); 
            
          vector<int> busesTobeRemoved;
          for(auto bus: busesNotVisited){
              //printf("bus: %d\n",bus);
              if(routesSet[bus].find(currStop) != routesSet[bus].end()){
                  for(auto stop: routesSet[bus]){
                      if(stopsVisited.find(stop) == stopsVisited.end()){
                          stopsVisited.insert(stop);
                          q.push(stop);

                          if(resultMap.find(stop) == resultMap.end()){
                              resultMap[stop] = resultMap[currStop] + 1;
                          }
                      }
                  }
                  
                  busesTobeRemoved.push_back(bus);
              } 
          }

          for(auto bus: busesTobeRemoved){
              busesNotVisited.erase(bus);
          }

//          for(auto m: resultMap){
//              printf("k: %d, v: %d", m.first, m.second);
//          }
//          printf("\n");
       }

       if(resultMap.find(target) != resultMap.end()){
           return resultMap[target];
       } else {
           return -1;
       }
    }
};

int main() {

    Solution sol;

    vector<vector<int>> t1 = {{1,2,7},{3,6,7}};
    printf("Min buses: %d\n", sol.numBusesToDestination(t1, 1, 6));

    vector<vector<int>> t2 = {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    printf("Min buses: %d\n", sol.numBusesToDestination(t2, 15, 12));
}

