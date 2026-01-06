n, m = map(int, input().split())
taro_exist = [False for _ in range(n)]

for _ in range(m):
  a, b = input().split()
  ai = int(a) - 1
  
  if b == 'F' or taro_exist[ai]:
    print('No')
    
  else:
    print('Yes')
    taro_exist[ai] = True