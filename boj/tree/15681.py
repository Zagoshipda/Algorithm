'''
    https://www.acmicpc.net/problem/15681
    (tree and query)

    reference
        https://www.acmicpc.net/source/69400180
        (ckswofl, 404 ms)
        https://www.acmicpc.net/source/87297443
        (vincent0116, 364 ms)

'''

import sys

NUM_VERTEX = 100_000    # 10^5
NUM_QUERY = 100_000     # 10^5

N, R, Q = list(map(int, input().split()))

graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
dp = [0] * (N + 1)

# sys.setrecursionlimit(NUM_VERTEX + 1)       # recursion error
sys.setrecursionlimit(N << 1)      # AC

def dfs(curr : int) -> int:
    visited[curr] = True

    cnt = 1     # count itself
    for next in graph[curr]:
        if not visited[next]:
            cnt += dfs(next)

    dp[curr] = cnt

    return cnt

def solve():
    dfs(R)

for _ in range(N - 1):
    # U, V = list(map(int, input().split()))                # TLE
    # U, V = list(map(int, sys.stdin.readline().split()))
    U, V = map(int, sys.stdin.readline().split())
    graph[U].append(V)
    graph[V].append(U)

solve()

for _ in range(Q):
    # U = list(map(int, input().split()))[0]
    # U = int(input())                                      # TLE
    U = int(sys.stdin.readline())

    print(dp[U])
