// https://leetcode.com/problems/the-skyline-problem/description/
//
#include <numeric>
#include <set>
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

class UnionFind {
  vector<int> arr;

public:
  UnionFind(int n) {
    arr.resize(n);
    iota(arr.begin(), arr.end(), 0);
  }

  int find(int x) {
    if (arr[x] != x) {
      return find(arr[x]);
    } else {
      return arr[x];
    }
  }

  int merge(int x, int y) {
    arr[x] = arr[y];
    return arr[y];
  }
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    int n = buildings.size();

    set<int> edges;

    for (int i = 0; i < n; i++) {
      edges.insert(buildings[i][0]);
      edges.insert(buildings[i][1]);
    }

    unordered_map<int, int> indexMap;
    int index = 0;
    for (auto itr = edges.begin(); itr != edges.end(); itr++, index++) {
      indexMap[*itr] = index;
    }

    sort(buildings.begin(), buildings.end(),
         [](auto &a, auto &b) { return a[2] > b[2]; });

    vector<int> heights(edges.size(), 0);
    UnionFind uf(edges.size());

    for (int i = 0; i < n; i++) {
      int leftIndex = uf.find(indexMap[buildings[i][0]]);
      int rightIndex = indexMap[buildings[i][1]];

      while (leftIndex < rightIndex) {
        heights[leftIndex] = buildings[i][2];

        uf.merge(leftIndex, rightIndex);

        leftIndex = uf.find(++leftIndex);
      }
    }

    vector<vector<int>> result;
    int currentHeight = -1;
    index = 0;

    for (auto itr = edges.begin(); itr != edges.end(); itr++, index++) {
      log("[%d -> %d], ", *itr, heights[index]);
      if (currentHeight != heights[index]) {
        result.push_back({*itr, heights[index]});
      }

      currentHeight = heights[index];
    }
    log("\n");

    return result;
  }
};

void print2D(vector<vector<int>> arr) {
  printf("[");
  for (int i = 0; i < arr.size(); i++) {
    printf("[");
    for (int j = 0; j < arr[i].size(); j++) {
      printf("%d,", arr[i][j]);
    }
    printf("]");
  }
  printf("]\n");
}

int main() {
  Solution sol;

  // vector<vector<int>> buildings = {
  //     {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};

  // vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};

  // vector<vector<int>> buildings = {{0, 3, 3}, {1, 5, 3}, {2, 4, 3}, {3, 7,
  // 3}};

  // vector<vector<int>> buildings = {{0, 2, 3}, {2, 4, 3}, {4, 6, 3}};
  //
  // vector<vector<int>> buildings = {
  //    {4, 9, 10}, {4, 9, 15}, {4, 9 */, 12}, {10, 12, 10}, {10, 12, 8}};

  vector<vector<int>> buildings = {
      {1, 38, 219},  {2, 19, 228},  {2, 64, 106},  {3, 80, 65},   {3, 84, 8},
      {4, 12, 8},    {4, 25, 14},   {4, 46, 225},  {4, 67, 187},  {5, 36, 118},
      {5, 48, 211},  {5, 55, 97},   {6, 42, 92},   {6, 56, 188},  {7, 37, 42},
      {7, 49, 78},   {7, 84, 163},  {8, 44, 212},  {9, 42, 125},  {9, 85, 200},
      {9, 100, 74},  {10, 13, 58},  {11, 30, 179}, {12, 32, 215}, {12, 33, 161},
      {12, 61, 198}, {13, 38, 48},  {13, 65, 222}, {14, 22, 1},   {15, 70, 222},
      {16, 19, 196}, {16, 24, 142}, {16, 25, 176}, {16, 57, 114}, {18, 45, 1},
      {19, 79, 149}, {20, 33, 53},  {21, 29, 41},  {23, 77, 43},  {24, 41, 75},
      {24, 94, 20},  {27, 63, 2},   {31, 69, 58},  {31, 88, 123}, {31, 88, 146},
      {33, 61, 27},  {35, 62, 190}, {35, 81, 116}, {37, 97, 81},  {38, 78, 99},
      {39, 51, 125}, {39, 98, 144}, {40, 95, 4},   {45, 89, 229}, {47, 49, 10},
      {47, 99, 152}, {48, 67, 69},  {48, 72, 1},   {49, 73, 204}, {49, 77, 117},
      {50, 61, 174}, {50, 76, 147}, {52, 64, 4},   {52, 89, 84},  {54, 70, 201},
      {57, 76, 47},  {58, 61, 215}, {58, 98, 57},  {61, 95, 190}, {66, 71, 34},
      {66, 99, 53},  {67, 74, 9},   {68, 97, 175}, {70, 88, 131}, {74, 77, 155},
      {74, 99, 145}, {76, 88, 26},  {82, 87, 40},  {83, 84, 132}, {88, 99, 99}};

  print2D(sol.getSkyline(buildings));
}
