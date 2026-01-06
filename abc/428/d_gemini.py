import sys
import os
import math

# TLE対策: input() の代わりに sys.stdin.readline を使う
# input = sys.stdin.readline を定義
input = sys.stdin.readline

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    # input = sys.stdin.readline は input() と同じように
    # 読み込む関数を定義し直すテクニック
    # ローカルテスト時は input() をそのまま使う
    input = __builtins__.input 

numCase = int(input())
for _ in range(numCase):
    # c, d の読み込み
    c, d = map(int, input().split())
    
    # y = c+x の取りうる k (桁数) の k-1 (i) を計算
    # math.log10(1) は 0.0 なので、c=1 の場合も c+1 で正しく 0 から始まる
    log10_c_plus_1 = math.floor(math.log10(c + 1))
    log10_c_plus_d = math.floor(math.log10(c + d))

    sum_z = 0
    # 考えられる f の桁数 i を 1 つずつ試す
    for i in range(log10_c_plus_1, log10_c_plus_d + 1):
        # i は floor(log10(y)) = k-1
        k = i + 1
        
        # 現在の桁 k にするための x の範囲を定める
        # y (c+x) は 10**i から 10**(i+1)-1 まで
        # x は (10**i)-c から 10**(i+1)-c-1 まで
        min_x = max(1, 10**i - c)
        max_x = min(10**(i+1) - c - 1, d)

        # min_x > max_x の場合は、この桁数kの x は存在しない
        if min_x > max_x:
            continue
            
        # f(C, C+x) = C * 10^k + (C+x)
        min_f = c * (10**k) + c + min_x
        max_f = c * (10**k) + c + max_x

        # WA対策 (原因A): math.sqrt() の代わりに math.isqrt() を使う
        
        # min_z = ceil(sqrt(min_f)) の整数版
        min_z = math.isqrt(min_f)
        if min_z * min_z < min_f:
            min_z += 1
            
        # max_z = floor(sqrt(max_f)) の整数版
        max_z = math.isqrt(max_f)

        # WA対策 (原因B): max_z < min_z の場合に負にならないよう max(0, ...) でガード
        sum_z += max(0, max_z - min_z + 1)

    print(sum_z)