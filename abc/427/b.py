n = int(input())
A = 1

for _ in range(n - 1):
    A = A + sum(list(map(int, str(A))))

print(A)