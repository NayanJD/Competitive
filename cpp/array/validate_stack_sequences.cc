// https://leetcode.com/problems/validate-stack-sequences
//
// Given two integer arrays pushed and popped each with distinct values, return
// true if this could have been the result of a sequence of push and pop
// operations on an initially empty stack, or false otherwise.

// Example 1:
//
// Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// Output: true
// Explanation: We might do the following sequence:
// push(1), push(2), push(3), push(4),
// pop() -> 4,
// push(5),
// pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// Example 2:
//
// Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// Output: false
// Explanation: 1 cannot be popped before 2.
//
//
// Constraints:
//
// 1 <= pushed.length <= 1000
// 0 <= pushed[i] <= 1000
// All the elements of pushed are unique.
// popped.length == pushed.length
// popped is a permutation of pushed.

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {

    int n = pushed.size();

    vector<int> stack;
    unordered_set<int> isPresent;

    int i = 0, j = 0;

    while (i < n) {
      stack.push_back(pushed[i]);
      isPresent.insert(pushed[i]);

      /* printf("Popping: %d\n", j); */

      if (popped[j] != stack.back() &&
          isPresent.find(popped[j]) != isPresent.end()) {
        return false;
      }

      while (!stack.empty() && popped[j] == stack.back()) {
        stack.pop_back();
        isPresent.erase(popped[j]);
        j++;
      }

      i++;
    }

    while (j < n) {
      if (popped[j] != stack.back()) {
        return false;
      }

      j++;
      stack.pop_back();
    }

    return true;
  }
};

int main() {
  Solution sol;

  vector<int> pushed = {1, 2, 3, 4, 5};
  vector<int> popped = {4, 5, 3, 2, 1};

  /* vector<int> pushed = {1, 2, 3, 4, 5}; */
  /* vector<int> popped = {4, 3, 5, 1, 2}; */

  /* vector<int> pushed = {1, 2, 3, 4, 5}; */
  /* vector<int> popped = {1, 2, 3, 4, 5}; */

  printf("Validate Stack Sequence: %d\n",
         sol.validateStackSequences(pushed, popped));
}
