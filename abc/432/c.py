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

n, x, y = map(int, input().split())
A = list(map(int, input().split()))

# 大と小の差
diff = y - x
# 基準のあまりの値
exo = A[0] * x % diff
min_sum = x * A[0]
max_sum = y * A[0]

mins = [min_sum]

for a in A[1:]:
    #print(min_sum, max_sum)
    a_min_sum = a * x
    if a_min_sum % diff != exo:
        print(-1)
        sys.exit()
    mins.append(a_min_sum)
    a_max_sum = a * y
    #print(a_min_sum, a_max_sum)
    if min_sum > a_max_sum or max_sum < a_min_sum:
        print( -1)
        sys.exit()
    min_sum = max(min_sum, a_min_sum)
    max_sum = min(max_sum, a_max_sum)

#print(min_sum, max_sum)
result = 0

for m in mins:
    result += (max_sum - m) // diff

print(result)