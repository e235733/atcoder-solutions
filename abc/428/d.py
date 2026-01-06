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
    c, d = map(int, input().split())
    #print('now about', c, d)
    
    # cとdが10の何乗なのか
    log10_c = math.floor(math.log10(c))
    log10_c_plus_d = math.floor(math.log10(c+d))
    #print('log10_c =',log10_c,', log10_c_plus_d' , log10_c_plus_d)

    sum_z = 0
    # 考えられるfの桁数を1つずつ試す
    for i in range(log10_c, log10_c_plus_d+1):
        # 現在の桁にするための x の範囲を定める
        min_x = max(1, 10**i-c)
        max_x = min(10**(i+1)-c-1, d)
        #print(min_x, max_x)

        min_f = c*10**(i+1) + min_x + c
        max_f = c*10**(i+1) + max_x + c
        min_z = math.isqrt(min_f)
        if min_z**2 < min_f:
            min_z += 1
        max_z = math.isqrt(max_f)
        #print(min_f, max_f, min_z, max_z)
        num_z = max_z - min_z + 1
        if num_z > 0:
            sum_z += num_z

    print(sum_z)