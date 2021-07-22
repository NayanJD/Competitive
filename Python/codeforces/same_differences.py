# https://codeforces.com/contest/1520/problem/D

import sys

input_str = sys.stdin.read()

input_arr = input_str.split("\n")

t = int(input_arr[0])

input_arr = input_arr[1:]

i = 0
while i < 2 * t:
    n = int(input_arr[i])
    arr = [int(val) for val in input_arr[i + 1].split(" ")]

    diff_dict = {}
    res = 0
    for j in range(len(arr)):
        diff = arr[j] - j

        if diff in diff_dict:
            res += diff_dict[diff]
            diff_dict[diff] = diff_dict[diff] + 1
        else:
            diff_dict[diff] = 1

    i = i + 2

    print(res)