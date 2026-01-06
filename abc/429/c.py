import collections

n = int(input())
A = list(map(int, input().split()))
B = []
count = 0

c = collections.Counter(A)
for v in c.values():
    if v >= 2:
        count += v * (v - 1) // 2 * (n - v)

print(count)