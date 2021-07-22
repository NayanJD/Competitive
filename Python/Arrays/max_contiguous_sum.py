# User function Template for python3


class Solution:
    ##Complete this function
    # Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self, a, size):
        ##Your code here
        maxSum = -9999999999999999
        maxSumTillNow = 0
        for i in range(size):
            print("maxSumTillNow ", maxSumTillNow)
            maxSumTillNow += a[i]

            if maxSumTillNow > maxSum:
                maxSum = maxSumTillNow

            if maxSumTillNow < 0:
                maxSumTillNow = 0

        return maxSum


if __name__ == "__main__":
    arr = [
        9,
        -51,
        -20,
        -13,
        -51,
        40,
        -21,
        75,
        -24,
        29,
        -86,
        5,
        -38,
        15,
        48,
        -87,
        -9,
        42,
        39,
        64,
        47,
        -63,
        22,
        -81,
        -20,
        -100,
        28,
    ]

    print(Solution().maxSubArraySum(arr, 27))
