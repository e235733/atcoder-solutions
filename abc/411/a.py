import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

p = input()
l = int(input())

if len(p) < l :
    print('No')
else:
    print('Yes')