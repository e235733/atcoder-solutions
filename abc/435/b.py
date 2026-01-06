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

n = int(input())
A = list(map(int, input().split()))

count_result = 0

for l in range(n-1):
    for r in range(l+1, n):
        #print('now about', l, r)
        # culcurate sum in the block
        block_sum = 0
        for i in range(l, r+1):
            block_sum += A[i]
        #print('block sum', block_sum)

        # find divisor
        is_dividable = False
        num_divisor = 0
        for i in range(l, r+1):
            #print('is', A[i], 'a divisor?')
            if block_sum % A[i] == 0:
                is_dividable = True
                #print('Yes!')
                break
            #print('No!')
        
        if not is_dividable:
            #print('block', l, r, 'is result')
            count_result += 1

print(count_result)