'''
    https://www.acmicpc.net/problem/10814
    (sort by age)

    reference
        https://www.acmicpc.net/board/view/148566
'''

import sys
from collections import deque
from heapq import *

input_line = sys.stdin.readline

MAX_STACK = 1_000_000
sys.setrecursionlimit(MAX_STACK)

'''

2
9 a
11 b

'''

def cmp(person):
    # return person[0]          # WRONG
    return int(person[0])       # AC

N = int(input_line())
inputs_list = [input_line().split() for _ in range(N)]  # age, name
inputs_list.sort(key= cmp)      # NOTE : stable sort

for age, name in inputs_list:
    print(age, name)

def solve():
    pass

solve()

