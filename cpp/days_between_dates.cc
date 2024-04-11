// https://leetcode.com/problems/number-of-days-between-two-dates/description/
//
// 1360. Number of Days Between Two date2Days
//
// Write a program to count the number of days between two dates.

// The two dates are given as strings, their format is YYYY-MM-DD as shown in
// the examples.
//
//
//
// Example 1:
//
// Input: date1 = "2019-06-29", date2 = "2019-06-30"
// Output: 1
// Example 2:
//
// Input: date1 = "2020-01-15", date2 = "2019-12-31"
// Output: 15
//
//
// Constraints:
//
// The given dates are valid dates between the years 1971 and 2100.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
  bool isLeapYear(int year) {
    if (year % 100 == 0) {
      return year % 400 == 0;
    } else {
      return year % 4;
    }
  }

  int countLeapYearsRange(int startYear, int endYear) {
    int days = (endYear / 4 - startYear / 4);

    days -= (endYear / 400 - startYear / 400);

    return days;
  }

  int daysBetweenDates(string date1, string date2) {
    string buff = "";

    int date1Year = stoi(date1.substr(0, 4));
    int date1Month = stoi(date1.substr(5, 2));
    int date1Days = stoi(date1.substr(8, 2));

    int date2Year = stoi(date2.substr(0, 4));
    int date2Month = stoi(date2.substr(5, 2));
    int date2Days = stoi(date2.substr(8, 2));

    int days{0};

    if (date1Year > date2Year) {
      swap(date1Year, date2Year);
      swap(date1Month, date2Month);
      swap(date1Days, date2Days);
    } else if (date1Year == date2Year && date1Month > date2Month) {
      swap(date1Month, date2Month);
      swap(date1Days, date2Days);
    } else if (date1Year == date2Year && date1Month == date2Month &&
               date1Days > date2Days) {
      swap(date1Days, date2Days);
    }

    printf("Dates after swapping\n");
    cout << "Date2: " << date2Year << "-" << date2Month << "-" << date2Days
         << endl;
    cout << "Date1: " << date1Year << "-" << date1Month << "-" << date1Days
         << endl;

    days += (date2Year - date1Year) * 365 +
            countLeapYearsRange(date1Year, date2Year);

    for (int i = date1Month - 1; i < 12; i++) {
      days += daysInMonths[i];
    }

    if (isLeapYear(date1Year)) {
      if (date1Month <= 2) {
        days++;
      }
    }

    days -= date1Days;

    for (int i = date2Month - 1; i < 12; i++) {
      days -= daysInMonths[i];

      if (i == 1 && isLeapYear(date2Year)) {
        days--;
      }
    }

    days += date2Days;

    return days;
  }
};

int main() {
  Solution sol;

  // string date1 = "2019-06-29";
  // string date2 = "2019-06-30";

  string date1 = "1999-01-01";
  string date2 = "2100-12-31";

  printf("Days: %d\n", sol.daysBetweenDates(date1, date2));
}
