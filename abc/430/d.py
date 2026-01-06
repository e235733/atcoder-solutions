import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

import math
n = int(input())
X = list(map(int, input().split()))

sorted_X = [0, X[0]]
prev_min_distance = X[0] * 2
for x in X[1:]:
    if x > sorted_X[-1]:
        print('最大の値を超えてきた', x)
        if sorted_X[-1] - sorted_X[-2] > x - sorted_X[-1]:
            prev_min_distance += x*2 - sorted_X[-1]*3 -sorted_X[-2]
        else:
            prev_min_distance += x - sorted_X[-1]
        sorted_X.append(x)
    else:
        print('どこかに挿入しなければならない', x)
        # 二分探索木を利用
        head = 0
        tale = len(sorted_X) - 1
        mid = math.floor(tale/2)
        while tale > head+1:
            # 調べる範囲の真ん中よりxが小さい場合
            if sorted_X[mid] > x:
                tale = mid
            else:
                head = mid
        # 挿入する場所の前の要素について、距離が変わらないか確かめる
        if head == 0:
            prev_min_distance += x - sorted_X[1]
        else:
            if sorted_X[head] - sorted_X[head-1] > x - sorted_X[head]:
                prev_min_distance += x - sorted_X[head]*2 + sorted_X[head-1]
        if tale == len(sorted_X) - 1:
            prev_min_distance += sorted_X[-2] - x 
        else:
            if sorted_X[tale+1] - sorted_X[tale] > sorted_X[tale] - x:
                prev_min_distance += sorted_X[tale]*2 - x - sorted_X[head-1]
        prev_min_distance += min(x - sorted_X[head], sorted_X[tale] - x)
        sorted_X.insert(tale, x)
    print(prev_min_distance)