import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

n, q = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

result0 = 0
for i in range(n):
    result0 += min(A[i], B[i])

#直前の状態を保存しておく変数たち
prev_result = result0
prev_A = A
prev_B = B

#クエリをinputしながら実行していく
for _ in range(q):
    Q = input().split()
    c = Q[0]
    #xはインデックスなので -1しておく
    x = int(Q[1]) - 1
    v = int(Q[2])
    diff_min = 0

    if c == 'A':
        #直前のmin(A, B)と変更後のmin(A, B)を比較
        diff_min = min(v, prev_B[x]) - min(prev_A[x], prev_B[x])
        #次の値をセットする
        prev_A[x] = v
    else:
        diff_min = min(prev_A[x], v) - min(prev_A[x], prev_B[x])
        prev_B[x] = v
    
    result = prev_result + diff_min
    print(result)
    prev_result = result