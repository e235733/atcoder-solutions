n, q = map(int,input().split())
#バージョンiのPCの台数
num_ver = [1] * (n+1)
num_ver[0] = 0
#print(num_ver_i)

oldest_ver = 1

for _ in range(q):
    x, y = map(int, input().split())
    num_old = 0
    if oldest_ver <= x:
        for i in range(oldest_ver, x+1):
            num_old += num_ver[i]
        num_ver[y] += num_old
        oldest_ver = x+1
        print(num_old)
    else:
        print(0)