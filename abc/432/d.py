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

# 嵐によって変化した部分。[0]~[1]が x のサイズ, [2]~[3]が y のサイズ
parts = [[0, x-1, 0, y-1]]

for _ in range(n):
    c, str_a, str_b = input().split()
    [a, b] = map(int, [str_a, str_b])
    print('入力は', c, a, b)

    # 全てのパーツに対して実行する
    for i in range(len(parts)):
        print(i, '個目のパーツ', parts[i], 'について調べる')
        if c == 'X':
            # a よりもパーツが左にある場合
            if a > parts[i][1]:
                parts[i][2] -= b
                parts[i][3] -= b
            elif a <= parts[i][0]:
                parts[i][2] += b
                parts[i][3] += b
            else:
                # 右側の上がるパーツを、新たなパーツとして追加する
                new_part = []
                new_part.append(a)
                new_part.append(parts[i][1])
                new_part.append(parts[i][2] + b)
                new_part.append(parts[i][3] + b)
                parts.append(new_part)

                # すでにあるパーツを、左側の下がるパーツに書き換える
                parts[i][1] = a - 1
                parts[i][2] -= b
                parts[i][3] -= b

        if c == 'Y':
            # a よりもパーツが左にある場合
            if a > parts[i][3]:
                parts[i][0] -= b
                parts[i][1] -= b
            elif a <= parts[i][2]:
                parts[i][0] += b
                parts[i][1] += b
            else:
                # 上側の右に移動するパーツを、新たなパーツとして追加する
                new_part = []
                new_part.append(parts[i][0] + b)
                new_part.append(parts[i][1] + b)
                new_part.append(a)
                new_part.append(parts[i][3])
                parts.append(new_part)
                
                # すでにあるパーツを、左側の下がるパーツに書き換える
                parts[i][0] -= b
                parts[i][1] -= b
                parts[i][3] = a - 1
    print('全てのパーツは', parts)

    num_parts = len(parts)
    combination = []
    # 隣接しているパーツの組み合わせを調べる
    for i in range(num_parts-1):
        for j in range(i+1, num_parts):
            # 2つのパーツのxが隣接しているなら
            if parts[i][0] - parts[j][1] == 1 or parts[j][1] - parts[i][0]:
                # yの範囲に共通している部分があるなら
                if parts[i][2] <= parts[j][3] and parts[i][3] >= parts[j][2]:
                    combination.append({i, j})
    print('パーツの数は', num_parts, '組み合わせは', combination)

    left_combination = combination
    blocks = []
    # つながる組み合わせを見つける
    for target_com in left_combination:
        blocks.append(target_com)
