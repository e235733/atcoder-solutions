import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n = int(input())
# インデックスと番号を対応させる
# i 番目の人の見つめる先
s = [0] + list(map(int, input().split()))
# i 番目の人のゼッケン
z = [0] + list(map(int, input().split()))

# ゼッケン i をつけている人(ゼ:人)
z_to_p = [0] * (n+1)
# 人 i の見つめている先(人:人)
p_to_p = [0] * (n+1)
# 人 i のゼッケン(人:ゼ)
p_to_z = [0] * (n+1)
for i in range(n):
    z_to_p[z[i+1]] = i+1
    p_to_p[i+1] = s[i+1]
    p_to_z[i+1] = z[i+1]


result = []

# ゼ -> 人　-> 人 -> ゼッケン でたどる
for i in range(n):
    result.append(p_to_z[p_to_p[z_to_p[i+1]]])


print(*result)