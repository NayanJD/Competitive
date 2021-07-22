# https://codeforces.com/contest/1520/problem/E

import sys
from math import ceil, floor

input_str = sys.stdin.read()

input_arr = input_str.split("\n")

t = int(input_arr[0])

input_arr = input_arr[1:]

output_arr = []
for i in range(1, 2 * t, 2):
    pos_arr = []
    sheep_str = input_arr[i]

    for c in range(len(sheep_str)):
        if sheep_str[c] == "*":
            pos_arr.append(c)

    n = len(pos_arr)

    if n == 0:
        print(0)
        continue
    elif n == 1:
        m = 0
    else:
        m = floor(n / 2)

    xm = pos_arr[m]

    res = 0
    for k in range(len(pos_arr)):
        res += abs(pos_arr[k] - (xm - m + k))

    print(res)
