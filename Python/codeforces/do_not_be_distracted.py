# https://codeforces.com/contest/1520/problem/A

import sys

input_str = sys.stdin.read()

input_arr = input_str.split("\n")


t = int(input_arr[0])

input_arr = input_arr[1:]

output_arr = []
for i in range(1, 2 * t, 2):
    task_str = input_arr[i]
    unique_task = set([])

    verdict = "YES"
    curr = ""
    for j in range(len(task_str)):
        char = task_str[j]

        if char != curr:
            if char in unique_task:
                verdict = "NO"
                break
            else:
                unique_task.add(char)
                curr = char

    output_arr.append(verdict)

print("\n".join(output_arr))


# Short solution
# from itertools import *
# for s in[*open(0)][2::2]:print('YNEOS'[len([*groupby(s)])>len({*s})::2])