#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    int ex = 1, bitMask = 1, result = 0;

    for (int i = 0; i < 32; i++) 
{
      result += (a & bitMask);
      result += (b & bitMask);
      bitMask = bitMask << 1;
    }

    int test = 1;

    for (int i = 0; i < 32; i++) {
      test = test << 1;
    }

            printf("test is: %d, %d\n", test, (test & 5) == test);
    
    return result;
  }
};

int main() {
  Solution sol;

  int a = 101345876;
  int b = 222333444;

  printf("Sum of %d and %d is: %d\n", a, b, sol.getSum(a, b));
}
