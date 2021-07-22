# import sys

# input_str = sys.stdin.read()

# input_arr = input_str.split("\n")


# t = int(input_arr[0])

# input_arr = input_arr[1:]

# results = []
# for i in range(t):
#     n = int(input_arr[i])

#     div = int("1" * len(input_arr[i]))

#     results.append(n // div + 9 * (len(input_arr[i]) - 1))

# print("\n".join([str(val) for val in results]))


for s in[*open(0)][1:]:
    print(9*len(s)-18+int(c:=s[0])-('.'<s.strip(c)<c))