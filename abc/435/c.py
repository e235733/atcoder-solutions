import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n = int(input())
A = list(map(int, input().split()))
#print(n, A)

max_reach = 0
for i in range(n):
    #print('now about', A[i], 'in', i)
    next_reach = i + A[i] - 1
    #print('next reach', next_reach)
    if next_reach >= n-1:
        print(n)
        sys.exit()
    else:
        if A[i] == 1:
            if i == max_reach:
                break
            else:
                continue
        else:
            if next_reach > max_reach:
                max_reach = next_reach
            else:
                continue
        #print('max reach', max_reach)

print(max_reach+1)