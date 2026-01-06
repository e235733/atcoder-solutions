import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n, m, q = map(int, input().split())
permission = [0]
for _ in range(n):
    permission.append(set([]))
#print(permission)

for _ in range(q):
    query = list(map(int, input().split()))
    #print(permission)
    #print("query", query)
    if query[0] == 1:
        #print(permission[query[1]])
        if permission[query[1]] != 0:
            permission[query[1]].add(query[2])
            if len(permission[query[1]]) == m:
                permission[query[1]] = 0

    elif query[0] == 2:
        permission[query[1]] = 0
    
    else:
        #print(permission[query[1]])
        if permission[query[1]] == 0:
            print("Yes")
        else:
            if query[2] in permission[query[1]]:
                print("Yes")
            else:
                print("No")