// https://leetcode.com/problems/employee-free-time
//
// 759. Employee Free Time
//
// We are given a list schedule of employees, which represents the working time
// for each employee.

// Each employee has a list of non-overlapping Intervals, and these intervals
// are in sorted order.

// Return the list of finite intervals representing common, positive-length free
// time for all employees, also in sorted order.

// (Even though we are representing Intervals in the form [x, y], the objects
// inside are Intervals, not lists or arrays. For example, schedule[0][0].start
// = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we
// wouldn't include intervals like [5, 5] in our answer, as they have zero
// length.

// Example 1:

// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
// Output: [[3,4]]
// Explanation: There are a total of three employees, and all common
// free time intervals would be [-inf, 1], [3, 4], [10, inf].
// We discard any intervals that contain inf as they aren't finite.
// Example 2:

// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
// Output: [[5,6],[7,9]]

// Constraints:

// 1 <= schedule.length , schedule[i].length <= 50
// 0 <= schedule[i].start < schedule[i].end <= 10^8

#include <algorithm>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for an Interval.
class Interval {
public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

bool compareInterval(vector<int> &i1, vector<int> &i2) { return i1[0] < i2[0]; }

class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

    vector<vector<int>> flatennedSchedules;

    for (int i = 0; i < schedule.size(); i++) {

      for (int j = 0; j < schedule[i].size(); j++) {
        flatennedSchedules.push_back(
            {schedule[i][j].start, schedule[i][j].end});
      }
    }

    sort(flatennedSchedules.begin(), flatennedSchedules.end(), compareInterval);

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(flatennedSchedules[0][1]);

    vector<Interval> freeTime;
    int lastPopped{};
    for (int i = 1; i < flatennedSchedules.size(); i++) {

      while (!q.empty() && q.top() <= flatennedSchedules[i][0]) {
        lastPopped = q.top();
        q.pop();
      }

      if (q.empty() && lastPopped != flatennedSchedules[i][0]) {
        freeTime.push_back(Interval(lastPopped, flatennedSchedules[i][0]));
      }

      q.push(flatennedSchedules[i][1]);
    }

    return freeTime;
  }
};

int main() {
  vector<vector<vector<int>>> scheduleArr = {
      {{1, 2}, {5, 6}}, {{1, 3}}, {{4, 10}}};

  // vector<vector<vector<int>>> scheduleArr = {
  // {{1, 3}, {6, 7}}, {{2, 4}}, {{2, 5}, {9, 12}}};

  vector<vector<Interval>> schedule;

  for (auto e : scheduleArr) {
    vector<Interval> si;

    for (auto s : e) {
      si.push_back(Interval(s[0], s[1]));
    }

    schedule.push_back(si);
  }

  Solution sol;

  auto freeTime = sol.employeeFreeTime(schedule);

  for (auto t : freeTime) {
    printf("[%d,%d], ", t.start, t.end);
  }
  printf("\n");

  // char c;

  // int leftBraceDepth{};
  // int rightBraceDepth{3};

  // vector<Interval> employee;
  // Interval s;

  // while (cin >> c) {
  //   // printf("%c", c);
  //   if (c == '{') {
  //     leftBraceDepth++;
  //     rightBraceDepth--;
  //     printf("leftBraceDepth: %d, rightBraceDepth: %d\n", leftBraceDepth,
  //            rightBraceDepth);
  //   } else if (c == '}') {
  //     rightBraceDepth++;
  //     leftBraceDepth--;
  //     printf("leftBraceDepth: %d, rightBraceDepth: %d\n", leftBraceDepth,
  //            rightBraceDepth);
  //   }

  //   switch (c) {
  //   case '{':
  //     if (leftBraceDepth == 2) {
  //       employee.resize(0);
  //     }
  //     break;
  //   case '}':
  //     if (rightBraceDepth == 2) {
  //       vector<Interval> copyEmployee;
  //       copyEmployee = employee;

  //       printf("Pushing employee\n");
  //       schedule.push_back(copyEmployee);
  //       cin >> c;
  //     } else if (rightBraceDepth == 1) {
  //       Interval copyS = s;
  //       printf("Pushing schedule: %d, %d\n", s.start, s.end);
  //       employee.push_back(copyS);
  //       cin >> c;
  //     } else {
  //       // printf("Not doing anything\n");
  //     }
  //     break;
  //   default:
  //     cin >> c;
  //     s.start = c;
  //     cin >> c;
  //     cin >> c;
  //     s.end = c;
  //     printf("Read: %d,%d\n", s.start, s.end);
  //     break;
  //   }
  // }

  // printf("There are %d employees\n", schedule.size());
}
