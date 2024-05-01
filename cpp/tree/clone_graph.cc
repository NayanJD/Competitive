// https://leetcode.com/problems/clone-graph

#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *node) {
    unordered_map<int, Node *> newNodes;

    return cloneGraphDFS(node, newNodes);
  }

  Node *cloneGraphDFS(Node *node, unordered_map<int, Node *> &newNodes) {
    if (node == nullptr) {
      return nullptr;
    }

    if (newNodes.find(node->val) != newNodes.end()) {
      return newNodes[node->val];
    }

    Node *newNode = new Node(node->val);

    newNodes[node->val] = newNode;

    for (int i = 0; i < node->neighbors.size(); i++) {
      newNode->neighbors.push_back(cloneGraphDFS(node->neighbors[i], newNodes));
    }

    return newNode;
  }
};

Node *makeGraph(vector<vector<int>> &adjList) {
  if (adjList.size() == 0) {
    return nullptr;
  }

  vector<Node *> nodes(adjList.size());

  for (int i = 0; i < nodes.size(); i++) {
    nodes[i] = new Node(i + 1);
  }

  for (int i = 0; i < adjList.size(); i++) {
    for (auto neighbor : adjList[i]) {
      nodes[i]->neighbors.push_back(nodes[neighbor - 1]);
    }
  }

  return nodes[0];
}

void printDFS(Node *node, unordered_map<int, Node *> &visited) {
  if (node == nullptr) {
    return;
  }

  if (visited.find(node->val) != visited.end()) {
    return;
  }

  visited[node->val] = node;

  for (auto neighbour : node->neighbors) {
    printDFS(neighbour, visited);
  }
}

void printGraph(Node *node) {
  unordered_map<int, Node *> visited;

  printDFS(node, visited);

  int n = visited.size();

  log("[");
  for (int i = 0; i < n; i++) {
    log("[");
    for (auto neighbour : visited[i + 1]->neighbors) {
      log("%d,", neighbour->val);
    }
    log("],");
  }
  log("]\n");
}

int main() {
  Solution sol;

  // vector<vector<int>> graph = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};

  // printGraph(makeGraph(graph));
  // printGraph(sol.cloneGraph(makeGraph(graph)));

  vector<vector<int>> graph = {{}};
  printGraph(sol.cloneGraph(makeGraph(graph)));
}
