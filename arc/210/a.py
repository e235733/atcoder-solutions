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

n, q = map(int, input().split())
sum_addition = [0] * (n+1)

for _ in range(q):
    i, x = map(int, input().split())
    sum_addition[i] += x
print(sum_addition)

result_seq = [1]
for i in range(1, n):
    result_seq.append(result_seq[i-1]+sum_addition[i]+1)
print(result_seq)

print(sum(result_seq))