import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

x = int(input())

i = 1
m = 1
while m != x:
    i += 1
    m *= i

print(i)