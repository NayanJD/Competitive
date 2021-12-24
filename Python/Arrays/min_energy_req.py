class Solution:
    def min_energy(self, arr):
        n = len(arr)

        max_neg = 0

        tot = 0
        for ele in arr:
            tot += ele

            if tot < max_neg:
                max_neg = tot

        
        return -1 * max_neg + 1


if __name__ == '__main__':
    print(Solution().min_energy([3, -4, 2, 5 ,-11]))

