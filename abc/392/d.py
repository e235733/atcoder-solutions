import sys

input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

try:
    sys.stdin = open('input.txt', 'r')
except FileNotFoundError:
    pass

n = int(input()) 
k = [list(map(int, input().split())) for _ in range(n)]

# サイコロごとの、それぞれの値が出る確率 (i : (v : p))
probability = []
for i in range(n):
    # 空の辞書を設定しておく
    probability.append({})

# 各サイコロについて調べる
for i in range(n):
    # 各値の登場回数をカウントする
    count = {}
    for j in range(k[i][0]):
        if k[i][j+1] in count:
            count[k[i][j+1]] += 1
        else :
            count[k[i][j+1]] = 1
    #print(count)

    # それぞれの確率を保存する
    length = len(k[i]) - 1
    for v in count:
        probability[i][v] = count[v] / length

#print(probability)
# 最大確率
max_probability = 0

# すべてのサイコロの組み合わせを調べる
for i in range(n-1):
    for j in range(i+1, n):
        #print("about", i, "and", j)
        main = i
        sub = j
        # 短い方を選ぶ
        if len(probability[i]) < len(probability[j]):
            main = j
            sub = i
        # 同じ目が出る確率
        sum_multi_p = 0;
        for p in probability[main]:
            # もう一つのサイコロにも含まれる場合のみ
            if p in probability[sub]:
                sum_multi_p += probability[main][p] * probability[sub][p]
                #print("probability of", p, "is", probability[main][p] * probability[sub][p])
        #print("sum probability:", sum_multi_p)
        # 最大値の更新
        if sum_multi_p > max_probability:
            max_probability = sum_multi_p

print(max_probability)