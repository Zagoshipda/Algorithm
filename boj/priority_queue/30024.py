'''
    https://www.acmicpc.net/problem/30024
    (corn field)

    reference
        https://www.acmicpc.net/source/88934685
        (ever618, 588 ms)
'''

import sys
from heapq import *

input_line = sys.stdin.readline

'''

3 3
9 9 9
4 9 2
6 3 7
9

'''

NUM_ROW = 1_000             # 10^3
NUM_COL = 1_000             # 10^3
NUM_ITERATION = 100_000     # 10^5

moves = [
    (+1, 0),
    (-1, 0),
    (0, +1),
    (0, -1),
]

N, M = map(int, input_line().split())

corns = [list(map(int, input_line().split())) for _ in range(N)]

K = int(input_line())

visited = [[False] * M for _ in range(N)]
heap_max = []

def check_range(row, col) -> bool:
    return (0 <= row < N) and (0 <= col < M)

def solve_heap():
    # WRONG
    # for row in range(N):
    #     heappush(heap_max, (-corns[row][0], row, 0))
    #     heappush(heap_max, (-corns[row][M-1], row, M-1))

    #     visited[row][0] = True
    #     visited[row][M-1] = True

    # for col in range(1, M-1):
    #     heappush(heap_max, (-corns[0][col], 0, col))
    #     heappush(heap_max, (-corns[N-1][col], N-1, col))

    #     visited[0][col] = True
    #     visited[N-1][col] = True

    for row in range(N):
        heappush(heap_max, (-corns[row][0], row, 0))
        visited[row][0] = True
    if 1 < M:
        for row in range(N):
            heappush(heap_max, (-corns[row][M-1], row, M-1))
            visited[row][M-1] = True

    for col in range(1, M-1):
        heappush(heap_max, (-corns[0][col], 0, col))
        visited[0][col] = True
    if 1 < N:
        for col in range(1, M-1):
            heappush(heap_max, (-corns[N-1][col], N-1, col))
            visited[N-1][col] = True


    for _ in range(K):
        # -val, row, col = heappop(heap_max)    # ERROR
        # (val, row, col) = heappop(heap_max)     # val = -val
        val, row, col = heappop(heap_max)     # val = -val

        print(row + 1, col + 1)

        for move in moves:
            next_row = row + move[0]
            next_col = col + move[1]

            if check_range(next_row, next_col) and (not visited[next_row][next_col]):
                heappush(heap_max, (-corns[next_row][next_col], next_row, next_col))
                visited[next_row][next_col] = True

solve_heap()
