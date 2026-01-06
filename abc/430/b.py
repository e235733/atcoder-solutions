import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

n, m = map(int, input().split())
S = [input() for _ in range(n)]

#探索するm*m行列のサイズ
explore_size = n - m + 1

#部分的な塗られ方の種類
type_part_s = []
#print(explore_size)
for i in range(explore_size):
    for j in range(explore_size):
        next_part = []
        for k in range(m):
            part_s = S[i+k][j:j+m]
            next_part.append(part_s)
            #print(part_s)
        
        #print(type_part_s)
        if next_part in type_part_s:
            continue
        else:
            type_part_s.append(next_part)

print(len(type_part_s))