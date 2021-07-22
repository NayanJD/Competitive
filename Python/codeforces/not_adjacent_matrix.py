# https://codeforces.com/contest/1520/problem/C

import sys

input_str = sys.stdin.read()

input_arr = input_str.split("\n")

t = int(input_arr[0])

input_arr = input_arr[1:]

for i in range(t):
    n = int(input_arr[i])

    if n == 1:
        print(1)
    elif n == 2:
        print(-1)
    else:
        seed = 1
        for j in range(n):
            for k in range(n):
                if seed > n ** 2:
                    seed = 2

                print(seed, end=" ")
                seed += 2
            print()
