import sys
import os

if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')

from collections import Counter

n, sizeM, c = map(int, input().split())
A = list(map(int, input().split()))

counts = Counter(A)
# どの座標に人がいるかを示すmapA
mapA = sorted(counts.keys())
# その座標に何人いるかを示すnumP
numP = []
for a in mapA:
    numP.append(counts[a])

mapA += [m+sizeM for m in mapA]
numP += numP
#print(mapA)
#print(numP)

head = 0
# 頭の座標が０なら、スタート位置は1
if mapA[0] == 0:
    head = 1
mapA.append(sizeM*2)
numP.append(numP[0])

# taleは末尾+1のインデックス
tale = head
prev_point = 0

sumP = 0
result = 0

while mapA[head] <= sizeM:
    #print(prev_point, mapA[head])
    while sumP < c:
        sumP += numP[tale]
        tale += 1
    result += sumP * (mapA[head] - prev_point)
    #print(result, sumP, head, tale)
    
    sumP -= numP[head]
    prev_point = mapA[head]
    head += 1
if numP[head] < sizeM:
    while sumP < c:
        sumP += numP[tale]
        tale += 1
    result += sumP * (sizeM - prev_point)
print(result)