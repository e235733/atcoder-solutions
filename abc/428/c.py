q = int(input())
now_v = 0
is_ok = True
bad_i = None
now_len = 0
v = [0]

for i in range(q):
    #print(f'now_v:{now_v}, is_ok:{is_ok}, bad_i:{bad_i}, now_len:{now_len}, v:{v}')
    #print(f'入力{i+1}行目の処理開始')
    strings = list(input().split())
    #print(f'入力の内容は{strings}')
    if strings[0] == '1':
        now_len += 1
        if strings[1] == '(':
            now_v += 1
            print('No')
        else:
            now_v -= 1
            if now_v == 0 and is_ok == True:
                print('Yes')
            else:
                print('No')
                if now_v < 0 and is_ok == True:
                    is_ok = False
                    bad_i = now_len
        v.append(now_v)
    else:
        now_len -= 1
        v.pop()
        now_v = v[-1]
        if is_ok == False:
            if now_len < bad_i:
                is_ok = True
                print('Yes')
            else:
                print('No')
        else:
            if now_v == 0:
                print('Yes')
            else:
                print('No')