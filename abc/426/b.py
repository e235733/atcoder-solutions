s = input()
s0 = s[0]
s1 = s[1]

if s0 == s1:
    for i in s[2:]:
        if i != s0:
            print(i)
else:
    if s[2] == s0:
        print(s1)
    else:
        print(s0)