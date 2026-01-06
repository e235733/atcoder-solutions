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

S = input()
length = len(S)
#print(S, length)

prev_s = None
prev_num = 0

curr_s = S[0]
curr_num = 1

result = 0

for i in range(1, length):
    if S[i] == curr_s:
        curr_num += 1
    else:
        if prev_s != None:
            result += min(prev_num, curr_num)
            #print('now on', i, 'result', result)

        if int(S[i]) == int(curr_s) + 1:
            prev_s = curr_s
            prev_num = curr_num

            curr_s = S[i]
            curr_num = 1

        else:
            prev_s = None

            curr_s = S[i]
            curr_num = 1
    #print(prev_s, prev_num, curr_s, curr_num)

if prev_s != None:
    result += min(prev_num, curr_num)
    #print('finished', 'result', result)

print(result)