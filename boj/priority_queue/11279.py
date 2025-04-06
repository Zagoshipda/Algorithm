'''
    https://www.acmicpc.net/problem/11279
    (max heap)
'''

import sys
from heapq import *

NUM_OPERATION = 100_000

N = int(sys.stdin.readline())
heap_max = []

def solve_heap(val):
    if val:
        heappush(heap_max, -val)
    else:
        if heap_max:
            print(-heappop(heap_max))
        else:
            print(0)

for _ in range(N):
    x = int(sys.stdin.readline())
    solve_heap(x)
