class Solution:
    def getMinDiff(self, arr, n, k):
        # code here

        arr.sort()

        ans = arr[-1] - arr[0]

        small, big = 0, 0

        print("arr[0] + k ", arr[0] + k)
        print("arr[-1] - k", arr[-1] - k)
        for i in range(1, n):
            small = min(arr[0] + k, arr[i] - k)  # finding minimum tower height
            big = max(arr[i - 1] + k, arr[-1] - k)  # finding maximum tower height
            ans = min(ans, big - small)

            print(f"{i - 1} itr----")
            print("small ", small)
            print("big ", big)

        return ans


if __name__ == "__main__":
    li = [2, 6, 3, 4, 7, 2, 10, 3, 2, 1]

    print(Solution().getMinDiff(li, 10, 5))