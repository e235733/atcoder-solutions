import sys

# TLE対策 (PyPyでもinput()は遅い): 高速な入力を設定
# .rstrip() で末尾の改行コード\nを削除する
input = lambda: sys.stdin.readline().rstrip()

# TLE/RE対策: 再帰の上限を 10^6 程度に上げておく
sys.setrecursionlimit(10**6)

# ローカルテスト用のファイル入力リダイレクト
try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n, m = map(int, input().split())
num_birds = [0] * (m+1)
sum_weight = [0] * (m+1)

for i in range(n):
    bird, weight = map(int, input().split())
    num_birds[bird] += 1
    sum_weight[bird] += weight
#print(num_birds, sum_weight)

for i in range(m):
    print(sum_weight[i+1]/num_birds[i+1])