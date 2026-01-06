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

t = int(input())

for _ in range(t):
    n = int(input())
    S = input()

    # 同じ数字の最大連結数
    max_const_0 = 0
    max_const_1 = 0
    now_const_0 = 0
    now_const_1 = 0
    now_value = '0'

    num_0 = 0
    num_1 = 0

    for i in range(len(S)):
        if S[i] == '0':
            num_0 += 1
        else:
            num_1 += 1

        # 値ごとに、現在の連結数を+1
        if S[i] == now_value:
            if now_value == '0':
                now_const_0 += 1
            else:
                now_const_1 += 1
        # 値が前と違い、最大連結数より直前の連結数が大きければ値を更新
        else:
            if now_value == '0':
                if now_const_0 > max_const_0:
                    max_const_0 = now_const_0
                now_const_1 = 1
                now_value = '1'
            else:
                if now_const_1 > max_const_1:
                    max_const_1 = now_const_1
                now_const_0 = 1
                now_value = '0'
    
    if now_value == '0':
        if now_const_0 > max_const_0:
            max_const_0 = now_const_0
    else:
        if now_const_1 > max_const_1:
            max_const_1 = now_const_1

    #print(max_value, max_const)

    result_value_0 = (num_0 - max_const_0) * 2 + num_1
    
    result_value_1 = num_0 + (num_1 - max_const_1) * 2

    print(min(result_value_0, result_value_1)) 