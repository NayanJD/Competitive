// https://leetcode.com/problems/the-skyline-problem/description/
//
// A city's skyline is the outer contour of the silhouette formed by all the
// buildings in that city when viewed from a distance. Given the locations and
// heights of all the buildings, return the skyline formed by these buildings
// collectively.

// The geometric information of each building is given in the array buildings
// where buildings[i] = [lefti, righti, heighti]:
//
// lefti is the x coordinate of the left edge of the ith building.
// righti is the x coordinate of the right edge of the ith building.
// heighti is the height of the ith building.
// You may assume all buildings are perfect rectangles grounded on an absolutely
// flat surface at height 0.
//
// The skyline should be represented as a list of "key points" sorted by their
// x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
// endpoint of some horizontal segment in the skyline except the last point in
// the list, which always has a y-coordinate 0 and is used to mark the skyline's
// termination where the rightmost building ends. Any ground between the
// leftmost and rightmost buildings should be part of the skyline's contour.
//
// Note: There must be no consecutive horizontal lines of equal height in the
// output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is
// not acceptable; the three lines of height 5 should be merged into one in the
// final output as such: [...,[2 3],[4 5],[12 7],...]
//
// Example 1:
//
// Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
// Explanation:
// Figure A shows the buildings of the input.
// Figure B shows the skyline formed by those buildings. The red points in
// figure B represent the key points in the output list.
//
// Example 2:
//
// Input: buildings = [[0,2,3],[2,5,3]]
// Output: [[0,3],[5,0]]
//
//
// Constraints:
//
// 1 <= buildings.length <= 104
// 0 <= lefti < righti <= 231 - 1
// 1 <= heighti <= 231 - 1
// buildings is sorted by lefti in non-decreasing order.

#include <algorithm>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

// Define the debug logging macro.
#ifdef DEBUG
#define log(...) fprintf(stderr, __VA_ARGS__)
#else
#define log(...) (void)0
#endif

bool comparator(vector<int> a, vector<int> b) { return a[2] > b[2]; }

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {

    int n = buildings.size();

    vector<vector<int>> skyline, newBuildings;

    stable_sort(buildings.begin(), buildings.end(), comparator);

    log("Sorted -> ");
    for (int i = 0, j = 0; i < n; i++) {
      j = i + 1;

      log("[%d,%d,%d], ", buildings[i][0], buildings[i][1], buildings[i][2]);

      while (j < n && buildings[j][2] == buildings[i][2] &&
             buildings[j][0] <= buildings[j - 1][1]) {
        j++;
      }

      j--;

      newBuildings.push_back(
          {buildings[i][0], buildings[j][1], buildings[i][2]});

      i = j;
    }
    log("\n");

    map<int, int> spans;

    int newSpanStart, newSpanEnd;

    vector<int> toDeleteSpans;

    for (vector<int> building : newBuildings) {
      log("Processing: [%d,%d,%d]\n", building[0], building[1], building[2]);

      auto lowerBoundBuilding = spans.lower_bound(building[0]);

      newSpanStart = building[0];
      newSpanEnd = building[1];

      if (spans.size() == 0) {
        spans[newSpanStart] = newSpanEnd;
        log("Adding 1st edge: [%d,%d]\n", building[0], building[2]);
        skyline.push_back({building[0], building[2]});
        continue;
      }

      if (lowerBoundBuilding == spans.begin()) {

        if (lowerBoundBuilding->first > building[0]) {
          log("Adding equal edge: [%d,%d]\n", building[0], building[2]);

          skyline.push_back({building[0], building[2]});
        }

      } else {
        if (lowerBoundBuilding == spans.end() ||
            lowerBoundBuilding->first != building[0]) {
          lowerBoundBuilding--;
        }

        if (lowerBoundBuilding->second < building[0]) {
          log("Adding standalone edge: [%d,%d]\n", building[0], building[2]);

          skyline.push_back({building[0], building[2]});
          lowerBoundBuilding++;
        } else {
          newSpanStart = lowerBoundBuilding->first;
        }
      }

      auto upperBoundBuilding = spans.upper_bound(building[1]);

      toDeleteSpans.clear();

      for (; lowerBoundBuilding != upperBoundBuilding; lowerBoundBuilding++) {
        if (building[1] > lowerBoundBuilding->second) {
          newSpanEnd = building[1];
          log("Adding edge: [%d,%d]\n", lowerBoundBuilding->second,
              building[2]);
          skyline.push_back({lowerBoundBuilding->second, building[2]});
        } else {
          newSpanEnd = lowerBoundBuilding->second;
        }

        toDeleteSpans.push_back(lowerBoundBuilding->first);
      }

      for (int span : toDeleteSpans) {
        spans.erase(span);
      }

      spans[newSpanStart] = newSpanEnd;
    }

    for (auto span : spans) {
      skyline.push_back({span.second, 0});
    }

    sort(skyline.begin(), skyline.end());

    return skyline;
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
  //     {4, 9, 10}, {4, 9, 15}, {4, 9, 12}, {10, 12, 10}, {10, 12, 8}};

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
