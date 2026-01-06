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
    n, h = map(int, input().split())
    #print('about case', n, h)
    prev_able = [h, h]
    prev_t = 0
    have_result = True
    rules = []
    for _ in range(n):
        rules.append(list(map(int, input().split())))

    for i in range(n):
        next_able = []
        t = rules[i][0]
        l = rules[i][1]
        u = rules[i][2]
        next_able.append(max(1, prev_able[0]-(t-prev_t)))
        next_able.append(prev_able[1] + t - prev_t)

        prev_t = t

        if next_able[0] <= u and next_able[1] >= l:
            prev_able[0] = max(next_able[0], l)
            prev_able[1] = min(next_able[1], u)
        else:
            print('No')
            have_result = False
            break
    
    if have_result:
        print('Yes')
            