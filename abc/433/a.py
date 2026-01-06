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

x, y, z = map(int, input().split())

# 年齢の差
diff = x - y

if diff % (z - 1) != 0:
    print('No')
    sys.exit()

# x, yにとって何年後か
x_after = diff // (z-1) * z - x
y_after = diff // (z-1) - y
#print(x_after, y_after)

if x_after < 0 or y_after < 0:
    print('No')
    sys.exit()

if x_after == y_after:
    print('Yes')
else:
    print('No')