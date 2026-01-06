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

import math
w, x = map(int, input().split())

# w_g < x * B
# B > w_g/x

w_g = w*1000
if w_g % x != 0:
    print(math.ceil(w_g/x))
else:
    print(int(w_g/x) + 1)