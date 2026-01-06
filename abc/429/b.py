import sys

n, m = map(int, input().split())

matrix = list(map(int, input().split()))
sum_matrix = sum(matrix)
#print(sum_matrix)

if sum_matrix < m:
    print('No')

else:
    for i in range(n):
        if sum_matrix - matrix[i] == m:
            print('Yes')
            sys.exit()
    print('No')