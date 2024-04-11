#include <iostream>
#include <vector>

using namespace std;

int leastDistance(vector<int> &seats) {
  int n = seats.size();

  if (n == 1) {
    return seats[0] == 0 ? 1 : 0;
  }

  vector<int> dp(n, 0);

  for (int i = 0; i < n; i++) {
    if (seats[i] == 0) {
      dp[i] = 1;
    }
  }

  for (int i = 1; i < n; i++) {
    dp[i] = dp[i] + dp[i - 1];
  }

  int largest = 0;
  for (int j = n - 2; j >= 0; j--) {
    dp[j] = min(dp[j], dp[j + 1] + dp[j]);

    largest = max(largest, dp[j]);
  }

  return largest;
}
int main() {
  vector<int> seats = {1, 1, 0, 0, 1, 1, 1};
  printf("Max Distance: %d\n", leastDistance(seats));
}
