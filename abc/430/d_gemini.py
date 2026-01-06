import sys
import os
from sortedcontainers import SortedList

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

n = int(input())
X = list(map(int, input().split()))

# pos[i] = 人i の座標
pos = {0: 0}
# rev_pos[座標] = 人i
rev_pos = {0: 0}
# d[i] = 人i の現在の d_i (最短距離)
d = {}
# sl = 現在いる人の座標を昇順に保ったリスト
sl = SortedList([0])

total_sum = 0

# --- 1人目 (r=1) の到着を特別に処理 ---
if n >= 1:
    x1 = X[0] # 1人目の座標
    pos[1] = x1
    rev_pos[x1] = 1
    sl.add(x1)
    
    # d[0] (人0) の最短距離は x1
    d[0] = x1 
    # d[1] (人1) の最短距離も x1
    d[1] = x1 
    
    # 総和は d[0] + d[1]
    total_sum = d[0] + d[1]
    print(total_sum)

# --- 2人目 (r=2) から n人目 までをループで処理 ---
# X[1:] が 2人目以降の座標
for r in range(2, n + 1):
    x = X[r-1] # 新しく到着した人r の座標
    
    # 1. データを追加
    pos[r] = x
    rev_pos[x] = r
    sl.add(x) # O(logN) で挿入
    idx_x = sl.index(x) # O(logN) で挿入位置を特定
    
    # --- 影響を受ける人を特定 ---
    P_x = x
    # r=2以降は、P_L (左の隣人) は必ず存在する (最低でも人0がいる)
    P_L = sl[idx_x - 1] 
    P_R = sl[idx_x + 1] if idx_x < len(sl) - 1 else None

    # 2. 新しい人 (r) の d_r を計算して総和に加算
    dist_L = P_x - P_L
    dist_R = P_R - P_x if P_R is not None else float('inf')
    
    d_r = min(dist_L, dist_R)
    d[r] = d_r
    total_sum += d_r
    
    # 3. 左の隣人 (P_L) の d を更新
    person_L = rev_pos[P_L] # P_L の座標にいる人
    old_d_L = d[person_L]   # ★r=2以降は、d[person_L]は必ず存在する
    
    # P_L のさらに左 (P_LL) を確認
    P_LL = sl[idx_x - 2] if idx_x > 1 else None
    dist_LL = P_L - P_LL if P_LL is not None else float('inf')
    
    # P_L の新しい最短距離は (左の P_LL との距離) vs (右の P_x との距離)
    new_d_L = min(dist_LL, dist_L) # dist_L は P_x - P_L
    
    d[person_L] = new_d_L
    # 総和を (新しいd - 古いd) で更新
    total_sum += (new_d_L - old_d_L)

    # 4. 右の隣人 (P_R) の d を更新
    if P_R is not None:
        person_R = rev_pos[P_R] # P_R の座標にいる人
        old_d_R = d[person_R]   # ★d[person_R]は必ず存在する
        
        # P_R のさらに右 (P_RR) を確認
        P_RR = sl[idx_x + 2] if idx_x < len(sl) - 2 else None
        dist_RR = P_RR - P_R if P_RR is not None else float('inf')

        # P_R の新しい最短距離は (左の P_x との距離) vs (右の P_RR との距離)
        new_d_R = min(dist_R, dist_RR) # dist_R は P_R - P_x
        
        d[person_R] = new_d_R
        # 総和を (新しいd - 古いd) で更新
        total_sum += (new_d_R - old_d_R)
        
    print(total_sum)