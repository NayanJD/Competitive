# https://codeforces.com/contest/1547/problem/A

import sys

input_str = sys.stdin.read()

input_arr = input_str.split("\n\n")

t = int(input_arr[0])

input_arr = input_arr[1:]

for vals in input_arr:

    coord_lines = vals.split('\n')

    a_coords = list(map(lambda x: int(x), coord_lines[0].split(' ')))
    b_coords = list(map(lambda x: int(x), coord_lines[1].split(' ')))
    f_coords = list(map(lambda x: int(x), coord_lines[2].split(' ')))

    if a_coords[0] == b_coords[0] and a_coords[1] == b_coords[1]:
        print(0)
        continue
    
    if a_coords[0] == b_coords[0]:
        if a_coords[0] == f_coords[0] and (f_coords[1] < max(a_coords[1],b_coords[1]) and f_coords[1] > min(a_coords[1],b_coords[1])):
            print(abs(b_coords[1] - a_coords[1]) + 2)
        else:
            print(abs(b_coords[1] - a_coords[1]))
    elif a_coords[1] == b_coords[1]:
        if a_coords[1] == f_coords[1] and (f_coords[0] < max(a_coords[0],b_coords[0]) and f_coords[0] > min(a_coords[0],b_coords[0])):
            print(abs(b_coords[0] - a_coords[0]) + 2)
        else:
            print(abs(b_coords[0] - a_coords[0]))
    else:
        print(abs(b_coords[0] - a_coords[0]) + abs(b_coords[1] - a_coords[1]))
