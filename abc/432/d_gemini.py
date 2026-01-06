import sys

# 高速な入力を設定
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**7)

def solve():
    # 入力読み込み
    try:
        line1 = input().split()
        if not line1: return
        n = int(line1[0])
        x = int(line1[1])
        y = int(line1[2])
    except ValueError:
        return

    # parts: [x_min, x_max, y_min, y_max]
    parts = [[0, x - 1, 0, y - 1]]

    # 1. 嵐による長方形の分割と移動
    for _ in range(n):
        c, str_a, str_b = input().split()
        a = int(str_a)
        b = int(str_b)

        new_parts = []
        
        # リスト内包表記を使わず、平易なループで高速化
        if c == 'X':
            for p in parts:
                x1, x2, y1, y2 = p
                
                # a が範囲外(右) -> 全体を左側の動き(-b)
                if x2 < a:
                    new_parts.append([x1, x2, y1 - b, y2 - b])
                # a が範囲外(左) -> 全体を右側の動き(+b)
                elif x1 >= a:
                    new_parts.append([x1, x2, y1 + b, y2 + b])
                # a が範囲内 -> 分割
                else:
                    # 左側部分
                    new_parts.append([x1, a - 1, y1 - b, y2 - b])
                    # 右側部分
                    new_parts.append([a, x2, y1 + b, y2 + b])

        else: # c == 'Y'
            for p in parts:
                x1, x2, y1, y2 = p
                
                # a が範囲外(上) -> 全体を下側の動き(-b)
                if y2 < a:
                    new_parts.append([x1 - b, x2 - b, y1, y2])
                # a が範囲外(下) -> 全体を上側の動き(+b)
                elif y1 >= a:
                    new_parts.append([x1 + b, x2 + b, y1, y2])
                # a が範囲内 -> 分割
                else:
                    # 下側部分
                    new_parts.append([x1 - b, x2 - b, y1, a - 1])
                    # 上側部分
                    new_parts.append([x1 + b, x2 + b, a, y2])
        
        parts = new_parts

    # 2. グラフ構築 (隣接判定)
    num_parts = len(parts)
    adj = [[] for _ in range(num_parts)]

    # X座標(x1)でソートすることで、探索範囲を絞る(枝刈り)
    # parts自体をソートするとインデックスが変わるので注意
    parts.sort() 

    for i in range(num_parts):
        x1_i, x2_i, y1_i, y2_i = parts[i]
        
        for j in range(i + 1, num_parts):
            x1_j, x2_j, y1_j, y2_j = parts[j]

            # 【枝刈り】
            # ソート済みなので、相手(j)の左端が 自分(i)の右端+1 より大きければ
            # それ以降の長方形は絶対に接しないためループを抜ける
            if x1_j > x2_i + 1:
                break

            # 【隣接判定】
            # マス(x,y)が隣接する条件は |x1-x2| + |y1-y2| = 1
            # 長方形同士が接するのは以下の2パターン
            # A. X範囲が重なり(share_x)、Y座標が接している(touch_y)
            # B. Y範囲が重なり(share_y)、X座標が接している(touch_x)

            # max(始点同士) <= min(終点同士) なら範囲は重なっている
            share_x = max(x1_i, x1_j) <= min(x2_i, x2_j)
            share_y = max(y1_i, y1_j) <= min(y2_i, y2_j)
            
            # 接しているか (片方の終点 + 1 == もう片方の始点)
            touch_y = (y2_i + 1 == y1_j) or (y2_j + 1 == y1_i)
            touch_x = (x2_i + 1 == x1_j) or (x2_j + 1 == x1_i)

            if (share_x and touch_y) or (share_y and touch_x):
                adj[i].append(j)
                adj[j].append(i)

    # 3. DFSで連結成分の面積を計算
    visited = [False] * num_parts
    ans = []

    # 再帰ではなくスタックを使ったDFS (PyPyで高速)
    for i in range(num_parts):
        if visited[i]:
            continue

        # 新しい連結成分の探索開始
        visited[i] = True
        stack = [i]
        current_area_sum = 0

        while stack:
            u = stack.pop()
            # 面積加算: (x2 - x1 + 1) * (y2 - y1 + 1)
            # parts[u] には [x1, x2, y1, y2] が入っている
            p = parts[u]
            current_area_sum += (p[1] - p[0] + 1) * (p[3] - p[2] + 1)

            for v in adj[u]:
                if not visited[v]:
                    visited[v] = True
                    stack.append(v)
        
        ans.append(current_area_sum)

    # 結果出力
    ans.sort()
    print(len(ans))
    print(*ans)

if __name__ == '__main__':
    solve()