// https://leetcode.com/problems/closest-node-to-path-in-tree/description/
// https://cp-algorithms.com/graph/lca_binary_lifting.html
// 2277. Closest Node to Path in Tree
//
// You are given a positive integer n representing the number of nodes in a
// tree, numbered from 0 to n - 1 (inclusive). You are also given a 2D integer
// array edges of length n - 1, where edges[i] = [node1i, node2i] denotes that
// there is a bidirectional edge connecting node1i and node2i in the tree.

// You are given a 0-indexed integer array query of length m where query[i] =
// [starti, endi, nodei] means that for the ith query, you are tasked with
// finding the node on the path from starti to endi that is closest to nodei.
//
// Return an integer array answer of length m, where answer[i] is the answer to
// the ith query.
//
// Example 1:
//
// Input: n = 7, edges = [[0,1],[0,2],[0,3],[1,4],[2,5],[2,6]], query =
// [[5,3,4],[5,3,6]] Output: [0,2] Explanation: The path from node 5 to node 3
// consists of the nodes 5, 2, 0, and 3. The distance between node 4 and node 0
// is 2. Node 0 is the node on the path closest to node 4, so the answer to the
// first query is 0. The distance between node 6 and node 2 is 1. Node 2 is the
// node on the path closest to node 6, so the answer to the second query is 2.
//
// Example 2:
//
// Input: n = 3, edges = [[0,1],[1,2]], query = [[0,1,2]]
// Output: [1]
// Explanation:
// The path from node 0 to node 1 consists of the nodes 0, 1.
// The distance between node 2 and node 1 is 1.
// Node 1 is the node on the path closest to node 2, so the answer to the first
// query is 1.
//
// Example 3:
//
// Input: n = 3, edges = [[0,1],[1,2]], query = [[0,0,0]]
// Output: [0]
// Explanation:
// The path from node 0 to node 0 consists of the node 0.
// Since 0 is the only node on the path, the answer to the first query is 0.

#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {

  vector<int> tin, tout;
  vector<vector<int>> up;
  int timer{};

public:
  vector<int> closestNode(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &query) {
    int start{}, end{}, node{};

    vector<int> result;

    for (int i = 0; i < query.size(); i++) {
      start = query[i][0];
      end = query[i][1];
      node = query[i][2];

      if (start == node) {
        result.push_back(start);
        continue;
      }

      if (end == node) {
        result.push_back(end);
        continue;
      }

      if (isAncestor(end, start)) {
        swap(start, end);
      }

      if (isAncestor(start, end)) {
        if (isAncestor(end, node)) {
          result.push_back(end);
        } else if (isAncestor(start, node)) {
          result.push_back(node);
        } else {
          result.push_back(start);
        }
      } else {
        int level = up[start].size();

        for (int i = level; i >= 0; i--) {
          if (!isAncestor(up[level][i], node)) {
            level = up[level][i];
          }
        }
      }
    }
  }

  void dfs(int u, int v, vector<vector<int>> &edges) {
    tin[u] = ++timer;

    up[u][0] = v;

    for (int i = 1; i < up[u].size(); i++) {
      up[u][1] = up[up[u][i - 1]][i - 1];
    }

    for (auto edge : edges[u]) {
      if (u != v) {
        dfs(edge, u, edges);
      }
    }

    tout[u] = ++timer;
  }

  bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  }

  void preprocess(int n, vector<vector<int>> &edges) {
    int l = ceil(log2(n));
    up.resize(n, vector<int>(l + 1));
    tin.resize(n);
    tout.resize(n);

    dfs(0, 0, edges);
  }
};

int main() {

  Solution sol;

  int n = 7;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 5}, {2, 6}};
  vector<vector<int>> query = {{5, 3, 4}, {5, 3, 6}};

  vector<int> closestNodes = sol.closestNode(n, edges, query);

  for (int i = 0; i < closestNodes.size(); i++) {
    printf("Query: [%d,%d,%d] -> %d", query[i][0], query[i][1], query[i][2],
           closestNodes[i]);
  }
}
