n, m = map(int, input().split())
M = [list(map(int, input().split())) for _ in range(m)]

import itertools
# nの全ての分け方のリスト
sub_n = list(itertools.product(range(2), repeat = n))
min_rem = m

for vertice in sub_n:
    num_ok = 0
    for edge in M:
        if vertice[edge[0]-1] + vertice[edge[1]-1] == 1:
            num_ok += 1
    num_rem = m - num_ok
    if num_rem < min_rem:
        min_rem = num_rem

print(min_rem)