import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

head_pos = []
head_idx = 0

n = int(input())
last_snake_length = 0
for _ in range(n):
    query = list(map(int, input().split()))
    if query[0] == 1:
        if len(head_pos) == 0:
            head_pos.append(0)
        else:
            head_pos.append(head_pos[-1] + last_snake_length)
        last_snake_length = query[1]

    elif query[0] == 2:
        head_idx += 1

    elif query[0] == 3:
        print(head_pos[head_idx+query[1]-1] - head_pos[head_idx])
    
    #print(head_idx, head_pos)