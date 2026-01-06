import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n, q = map(int, input().split())
X = list(map(int, input().split()))

box = [0] * n
result = []

for i in range(q):
    if X[i] != 0:
        result.append(X[i])
        box[X[i]-1] += 1
    
    else:
        min_num = min(box)
        min_i = box.index(min_num)
        result.append(min_i+1)
        box[min_i] += 1

print(*result)