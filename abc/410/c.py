import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n, q = map(int, input().split())
A = []
for i in range(n):
    A.append(i+1)
#print(A)

head = 0

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        p = query[1]
        x = query[2]
        index = (head+p) % n - 1
        A[index] = x
    
    elif query[0] == 2:
        p = query[1]
        index = (head+p) % n - 1
        print(A[index])

    else:
        k = query[1]
        head += k