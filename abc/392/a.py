import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

a1, a2, a3 = map(int, input().split())

if a1 == a2 * a3 or a2 == a1 * a3 or a3 == a1 * a2:
    print("Yes")
else :
    print("No")
