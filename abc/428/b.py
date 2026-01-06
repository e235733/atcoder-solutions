n, k = map(int, input().split())
s = input()

listk = []
strs = []

for i in range(n-k+1):
    str = s[i: i+k]
    listk.append(str)
    if str not in strs:
        strs.append(str)

#print(listk)
#print(strs)

counts = []

for r in strs:
    #print(listk.count(r))
    counts.append(listk.count(r))

max_count = max(counts)
print(max_count)

max_str = []
for i in range(len(counts)):
    if counts[i] == max_count:
        max_str.append(strs[i])
#print(max_str)

result = sorted(max_str)
print(*result)