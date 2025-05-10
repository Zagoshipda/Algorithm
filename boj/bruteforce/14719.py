'''
    https://www.acmicpc.net/problem/14719
    (rainwater)
'''

import sys

input_line = sys.stdin.readline

'''

'''

MAX_HEIGHT = 500
MAX_WIDTH = 500

def solve():
    H, W = map(int, input_line().split())
    blocks = list(map(int, input_line().split()))

    ans = 0
    for idx in range(1, W-1):
        left_max = max(blocks[:idx])
        right_max = max(blocks[idx+1:])
        ans += max(0, min(left_max, right_max) - blocks[idx])
    print(ans)

solve()
