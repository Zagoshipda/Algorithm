'''
    https://www.acmicpc.net/problem/11286
    (min absolute value heap)
'''

import sys
from heapq import *

'''

'''

NUM_OPERATION = 100_000

N = int(sys.stdin.readline())
heap_abs = []

def solve_heap(val):
    if val:
        heappush(heap_abs, (abs(val), val))
    else:
        if heap_abs:
            print(heappop(heap_abs)[1])
        else:
            print(0)

for _ in range(N):
    x = int(sys.stdin.readline())
    solve_heap(x)
