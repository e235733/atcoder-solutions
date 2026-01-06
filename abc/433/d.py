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

n, m = map(int, input().split())
A = list(map(int, input().split()))

value_dicts = [0] + [{} for _ in range(10)]

for i in range(n):
    a = A[i]
    # 値の桁数
    dig = math.floor(math.log10(a)) + 1
    # 値をmで割った余り
    remain = a % m

    if remain in value_dicts[dig]:
        value_dicts[dig][remain] += 1
    else:
        value_dicts[dig][remain] = 1

#print(value_dicts)

result = 0

for dig in range(1, 11):
    for remain in value_dicts[dig]:
        survey = []
        #print('about dig', dig, 'remain', remain)
        for i in range(1, 11):
            re_remain = remain * (10**(i)) % m
            if re_remain == 0:
                survey.append([i, 0])
            else:
                survey.append([i, m - re_remain])
        #print(survey)

        #print('beginning survey')
        for s in survey:
            #print('now about', s)
            #print(s[1], value_dicts[s[0]])
            if s[1] in value_dicts[s[0]]:
                #print(value_dicts[s[0]][s[1]], value_dicts[dig][remain])
                result += value_dicts[s[0]][s[1]] * value_dicts[dig][remain]

print(result)