'''
    https://www.acmicpc.net/problem/1068
    (tree)

    solution
        https://www.acmicpc.net/source/82712097
        (dlstk3031, 36 ms) : implemented in solve_3()

    reference
        https://www.acmicpc.net/board/view/132447

'''

import sys

input_line = sys.stdin.readline

MAX_STACK = 1_000_000
sys.setrecursionlimit(MAX_STACK)

'''

ex.

4
3 2 -1 2
0

# 2 (O)
# 1 (X)


2
1 -1
0
// 1



'''

NUM_VERTEX = 50


N = int(input_line())
parents = list(map(int, input_line().split()))
K = int(input_line())

graph = [[] for _ in range(N)]
visited = [False] * N

ROOT = -1

def build_tree():
    global ROOT

    for curr, parent in enumerate(parents):
        if parent != -1:
            graph[curr].append(parent)
            graph[parent].append(curr)
        else:
            ROOT = curr

build_tree()



removed = 0
def dfs_1(curr):
    global removed

    visited[curr] = True

    if len(graph[curr]) == 1:
        removed += 1
        return

    for next in graph[curr]:
        if not visited[next]:
            dfs_1(next)

def solve_1():
    # initial # of leaves
    cnt = 0
    for node in range(N):
        if node != ROOT and len(graph[node]) == 1:
            cnt += 1

    # count # of removes
    if parents[K] != -1:        # if NOT root
        visited[parents[K]] = True
    dfs_1(K)

    # # of newly created leaves
    added = 0
    if K != ROOT:
        # 1. removed node is the only child of the other node => parent now become a leaf
        # 2. removed node is the only child of the ROOT => ROOT now become a leaf
        if (parents[K] != ROOT and len(graph[parents[K]]) == 2) or \
            (parents[K] == ROOT and len(graph[parents[K]]) == 1):
            added += 1

    print(cnt - removed + added)



# method 2 : rebuild the tree
cnt_2 = 0
graph_2 = [[] for _ in range(N)]

def dfs_2(curr):
    visited[curr] = True
    parents[curr] = -1

    for next in graph[curr]:
        if (next != parents[curr]) and (not visited[next]):
            # parents[next] = -1
            dfs_2(next)

def dfs_3(curr):
    global cnt_2
    visited[curr] = True

    # if len(graph_2[curr]) == 1:
    #     cnt_2 += 1
    #     return

    is_child = True
    for next in graph_2[curr]:
        if not visited[next]:
            is_child = False
            dfs_3(next)

    if is_child:
        cnt_2 += 1

def solve_2():
    ROOT = -1
    for curr, parent in enumerate(parents):
        if parent != -1:
            graph[curr].append(parent)
            graph[parent].append(curr)
        else:
            ROOT = curr

    # dfs_2(K)
    visited[K] = True       # marking

    for curr, parent in enumerate(parents):
        if parent != -1:
            graph_2[curr].append(parent)
            graph_2[parent].append(curr)

    if not visited[ROOT]:
        dfs_3(ROOT)

    print(cnt_2)



# method 3 : erase first, count second
count_3 = 0

def dfs_erase(curr):
    visited[curr] = True

    for next in graph[curr]:
        if next != parents[curr]:
            dfs_erase(next)

def dfs_count_3(curr):
    global count_3
    visited[curr] = True

    is_leaf = True
    for next in graph[curr]:
        if not visited[next]:
            is_leaf = False
            dfs_count_3(next)

    if is_leaf:
        count_3 += 1

def solve_3():
    global ROOT

    # if ROOT == K:
    #     print(0)
    #     return

    dfs_erase(K)

    if not visited[ROOT]:
        dfs_count_3(ROOT)

    print(count_3)

def solve():
    solve_1()
    # solve_2()
    # solve_3()

solve()

