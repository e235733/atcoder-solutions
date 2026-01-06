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

X = input()
list_x = list(X)
#print(list_x)

min_x = 9
for x in list_x:
    if int(x) < min_x and int(x) != 0:
        min_x = int(x)
#print(min_x)
first_x = min_x
list_x.remove(str(first_x))
#print(first_x, list_x)

sorted_x = sorted(list_x)
print(str(first_x)+''.join(sorted_x))