import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n, m = map(int, input().split())
A = list(map(int, input().split()))

# 存在しない数字をリストに入れていく
result = []

for i in range(n):
    # 数字を含んでいなければ追加
    if i+1 not in A :
        result.append(i+1)

# 昇順にソート
result.sort()

print(len(result))
print(*result)