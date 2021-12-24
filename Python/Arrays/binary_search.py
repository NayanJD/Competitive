# https://www.geeksforgeeks.org/binary-search/

import sys


class Solution:
    ##Complete this function
    def searchInSorted(self, arr, N, K):
        # Your code here
        i = 0
        j = N - 1

        while i < j:
            m = (i + j) // 2

            if arr[m] > K:
                j = m - 1
            elif arr[m] < K:
                i = m + 1
            else:
                return 1

        if arr[i] == K:
            return i
        else:
            return -1


if __name__ == "__main__":
    print(Solution().searchInSorted([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 10, 4))
