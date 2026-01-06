x, y = input().split()
os_list = ["Ocelot", "Serval", "Lynx"]

if os_list.index(x) >= os_list.index(y):
    print('Yes')
else:
    print('No')