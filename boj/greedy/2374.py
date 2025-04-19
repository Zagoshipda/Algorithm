'''
    https://www.acmicpc.net/problem/2374
    (make the same number 1)

    similar problem
        https://www.acmicpc.net/problem/13146
        (make the same number 2)

    solution
        https://www.acmicpc.net/source/50385672
        (becl3ver, 0 ms)
'''

import sys

input_line = sys.stdin.readline
ARR_SIZE = 1_000            # 10^3
MAX_NUM = 1_000_000_000     # 10^9

'''

'''

n = int(input_line())
# arr = list(map(int, input_line().split()))
arr = [int(input_line()) for _ in range(n)]

def solve():
    adds = 0
    stk = []
    stk.append(arr[0])

    for ai in arr:
        if stk[-1] >= ai:
            stk.append(ai)
        else:
            adds += ai - stk[-1]
            while stk and stk[-1] < ai:
                stk.pop()
            stk.append(ai)

    if stk:
        adds += stk[0] - stk[-1]

    print(adds)

solve()
