import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

n, q = map(int, input().split())
A = list(map(int, input().split()))

numBlackBlock = 0
# マスの配列。0は白に、1は黒に対応
M = [0] * (n+2)
#print(M)
# 変化させる前後のマスの状態によって場合分け
for a in A:
    if M[a-1] == 0:
        if M[a] == 0:
            if M[a+1] == 0:
                numBlackBlock += 1
                M[a] = 1
            else:
                M[a] = 1
        else:
            if M[a+1] == 0:
                numBlackBlock -= 1
                M[a] = 0
            else:
                M[a] = 0
    else:
        if M[a] == 0:
            if M[a+1] == 0:
                M[a] = 1
            else:
                numBlackBlock -= 1
                M[a] = 1
        else:
            if M[a+1] == 0:
                M[a] = 0
            else:
                numBlackBlock += 1
                M[a] = 0
    print(numBlackBlock)