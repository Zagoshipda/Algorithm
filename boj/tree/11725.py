'''
    https://www.acmicpc.net/problem/11725
    (tree parents)
'''

import sys
from collections import deque
from queue import Queue

input_line = sys.stdin.readline

MAX_STACK = 1_000_000
sys.setrecursionlimit(MAX_STACK)

'''

'''

ROOT = 1

N = int(input_line())

graph = [[] for _ in range(N + 1)]
parent = [-1] * (N + 1)
visited = [False] * (N + 1)

for _ in range(N - 1):
    u, v = map(int, input_line().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(curr):
    visited[curr] = True

    for next in graph[curr]:
        if not visited[next]:
            parent[next] = curr
            dfs(next)

def print_answer():
    for node in range(2, N + 1):
        print(parent[node])

def solve_dfs():
    dfs(ROOT)

    print_answer()

def solve_bfs_1():
    # que = deque([])
    que = deque()
    que.append(ROOT)

    while que:
        curr = que.popleft()
        visited[curr] = True

        for next in graph[curr]:
            if not visited[next]:
                parent[next] = curr
                que.append(next)

    print_answer()

def solve_bfs_2():
    que = Queue()
    que.put(ROOT)

    while que:
        curr = que.get()
        visited[curr] = True

        for next in graph[curr]:
            if not visited[next]:
                parent[next] = curr
                que.put(next)

    print_answer()

def solve():
    # solve_dfs()   # 292 ms
    solve_bfs_1()     # 292 ms
    # solve_bfs_2()       # TLE

solve()
