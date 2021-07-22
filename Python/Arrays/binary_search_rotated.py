# https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1


class Solution:
    def search(self, A: list, l: int, h: int, key: int):
        # Complete this function

        while l < h:
            m = (l + h) // 2

            if A[m] == key:
                return m
            elif A[m] > A[l]:
                if key >= A[l] and key < A[m]:
                    h = m - 1
                else:
                    l = m + 1
            else:
                if key <= A[h] and key > A[m]:
                    l = m + 1
                else:
                    h = m - 1

        if key == A[l]:
            return l
        else:
            return -1


if __name__ == "__main__":
    print(Solution().search([5, 6, 7, 8, 9, 10, 1, 2, 3], 0, 8, 10))
