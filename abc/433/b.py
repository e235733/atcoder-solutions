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

n = int(input())
A = list(map(int, input().split()))

# 最初の出力は絶対に-1
print(-1)

for i in range(1, n):
    a = A[i]
    nearest = -2
    for j in range(i):
        if a < A[j] and nearest < j:
            nearest = j
    print(nearest + 1)
    nearest = -2