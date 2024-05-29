// https://leetcode.com/problems/alien-dictionary/description/
//
// 269. Alien Dictionary
//
// There is a new alien language that uses the English alphabet. However, the
// order of the letters is unknown to you.

// You are given a list of strings words from the alien language's dictionary.
// Now it is claimed that the strings in words are sorted lexicographically
//  by the rules of this new language.
//
// If this claim is incorrect, and the given arrangement of string in words
// cannot correspond to any order of letters, return "".
//
// Otherwise, return a string of the unique letters in the new alien language
// sorted in lexicographically increasing order by the new language's rules. If
// there are multiple solutions, return any of them.
//
//
//
// Example 1:
//
// Input: words = ["wrt","wrf","er","ett","rftt"]
// Output: "wertf"
// Example 2:
//
// Input: words = ["z","x"]
// Output: "zx"
// Example 3:
//
// Input: words = ["z","x","z"]
// Output: ""
// Explanation: The order is invalid, so return "".
//
//
// Constraints:
//
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

class Solution {
  unordered_map<char, unordered_set<char>> tree;
  vector<string> words;

public:
  string alienOrder(vector<string> &words) {
    this->words = words;

    for (auto word : words) {
      for (auto c : word) {
        tree[c] = {};
      }
    }

    if (!createTree(0, words.size(), 0)) {
      return "";
    }

    unordered_set<char> visited, tempVisited;
    unordered_map<char, int> incomingEdges;

    for (auto entry : tree) {
      log("Visiting %c\n", entry.first);

      incomingEdges[entry.first] = 0;

      tempVisited.clear();

      if (visited.find(entry.first) == visited.end()) {
        log("%c not visited\n", entry.first);

        if (doesHaveCycle(entry.first, tempVisited)) {
          return "";
        }

        log("Nodes visited -> ");
        for (auto c : tempVisited) {
          log("%c,", c);
        }
        log("\n");

        visited.insert(tempVisited.begin(), tempVisited.end());
      }
    }

    string order = "";

    for (auto entry : tree) {
      for (auto child : entry.second) {
        incomingEdges[child]++;
      }
    }

    log("Incoming edges: ");
    vector<char> topNodes, newTopNodes;
    for (auto entry : tree) {
      log("%c -> %d, ", entry.first, incomingEdges[entry.first]);

      if (incomingEdges[entry.first] == 0) {
        topNodes.push_back(entry.first);
      }
    }

    log("\n");

    while (topNodes.size() != 0) {

      newTopNodes.clear();

      for (auto node : topNodes) {
        order.push_back(node);

        for (auto child : tree[node]) {
          incomingEdges[child]--;

          if (incomingEdges[child] == 0) {
            newTopNodes.push_back(child);
          }
        }
      }

      topNodes.clear();
      topNodes = newTopNodes;
    }

    return order;
  }

  bool doesHaveCycle(char node, unordered_set<char> &visited) {

    bool hasCycle{false};

    if (visited.find(node) != visited.end()) {
      return true;
    }

    visited.insert(node);

    for (auto child : tree[node]) {
      if (doesHaveCycle(child, visited)) {
        return true;
      }
    }

    visited.erase(node);

    return false;
  }

  bool createTree(int from, int to, int level) {
    if (from == to - 1) {
      return true;
    }

    int i = from;

    while (i < to) {
      if (words[i].size() == level) {
        i++;
        from = i;
        continue;
      }

      log("level: %d, i: %d, to: %d\n", level, i, to);

      if (i + 1 < to && words[i + 1].size() == level) {
        log("returning false\n");
        return false;
      }

      if (i == to - 1 || words[i][level] != words[i + 1][level]) {
        if (!createTree(from, i + 1, level + 1)) {
          return false;
        }

        from = i + 1;

        if (i != to - 1) {
          log("%c -> %c\n", words[i][level], words[i + 1][level]);

          tree[words[i][level]].insert(words[i + 1][level]);
        }
      }

      i++;
    }

    return true;
  }
};

int main() {
  Solution sol;

  vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};

  // vector<string> words = {"z", "x"};

  // vector<string> words = {"z", "x", "z"};

  // vector<string> words = {"za", "zb", "zc", "x", "x", "x"};

  // vector<string> words = {"ac", "ab", "zc", "zb"};

  // vector<string> words = {"a", "b", "ca", "cc"};

  // vector<string> words = {"abc", "ab"};

  log("Order: %s\n", sol.alienOrder(words).c_str());
}
