import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n = int(input())
A = list(map(int, input().split()))
k = int(input())

result = 0
for a in A:
    if a >= k:
        result += 1

print(result)