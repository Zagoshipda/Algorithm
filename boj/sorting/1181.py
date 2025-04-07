'''
    https://www.acmicpc.net/problem/1181
    (word sorting)

    reference
        https://www.acmicpc.net/source/83993772
        (tm5323, 48 ms)
'''

import sys
from collections import deque
from heapq import *

input_line = sys.stdin.readline

MAX_STACK = 1_000_000
sys.setrecursionlimit(MAX_STACK)

'''

'''


N = int(input_line())

inputs = []

# input_set = set()
# for _ in range(N):
#     # inputs.append(input_line().strip())
#     input_set.add(input_line().strip())

input_set = set([input_line().strip() for _ in range(N)])

def cmp(str):
    return (len(str), str)


def solve_1():
    for word in sorted(input_set, key=cmp, reverse=False):
        print(word)

def solve_2():
    # WRONG
    # ans = sorted(input_set, key=len)
    # ans.sort()

    ans = sorted(input_set)
    ans.sort(key=len)

    for word in ans:
        print(word)

def solve():
    # inputs.sort(key=cmp, reverse=False)
    # print(inputs)

    # solve_1()     # 100 ms
    solve_2()       # 88 ms

solve()

