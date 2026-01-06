import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

n = int(input())
D = list(map(int, input().split()))

for i in range(n):
    result = []
    for j in range(i+1, n):
        #print(D[i:j])
        result.append(sum(D[i:j]))
    print(*result)