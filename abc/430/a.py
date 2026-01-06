import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

a, b, c, d = map(int, input().split())

if c >= a:
    if d < b:
        print('Yes')
    else:
        print('No')
else:
    print('No')