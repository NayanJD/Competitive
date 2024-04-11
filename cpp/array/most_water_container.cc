#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1;

    int maxVolume = 0;

    while (i < j) {
      maxVolume = max(maxVolume, (j - i) * min(height[i], height[j]));

      if (height[i] < height[j]) {
        i++;
      } else if (height[i] > height[j]) {
        j--;
      } else {
        i++;
        j--;
      }
    }

    return maxVolume;
  }
};

int main() {
  Solution sol;

  // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  vector<int> height = {1, 1};

  printf("Max Area: %d\n", sol.maxArea(height));
}
