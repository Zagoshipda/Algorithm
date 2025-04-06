'''
    https://www.acmicpc.net/problem/1927
    (min heap)

    reference
        https://www.daleseo.com/python-priority-queue/
        https://www.daleseo.com/python-heapq/
'''

import sys
from queue import PriorityQueue

from heapq import *

NUM_OPERATION = 100_000

N = int(sys.stdin.readline())

que = PriorityQueue()
heap = []

def solve_pq(val):
    if val:
        que.put(val)
    else:
        if que.empty():
            print(0)
        else:
            print(que.get())

def solve_heap(val):
    if val:
        heappush(heap, val)
    else:
        if heap:
            print(heappop(heap))
        else:
            print(0)

for _ in range(N):
    x = int(sys.stdin.readline())
    # solve_pq(x)       # 228 ms
    solve_heap(x)       # 140 ms
