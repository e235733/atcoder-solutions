n, m = map(int, input().split())
#print(n, m)
S = [input() for _ in range(n)]
#print(S)
#各行は文字列として受け取られている

#mごとの投票の値の合計
sum_vote_m = [0] * m
#print(sum_vote_m)
for i in range(n):
    for j in range(m):
        sum_vote_m[j] += int(S[i][j])

#nごとのスコア
sum_score_n = [0] * n
#各回で、mの合計がn/2より大きければ
for i in range(n):
    for j in range(m):
        if sum_vote_m[j] > n/2 and S[i][j] == '0':
            sum_score_n[i] += 1
        elif sum_vote_m[j] < n/2 and S[i][j] == '1':
            sum_score_n[i] += 1

max_score = max(sum_score_n)
result = []
for i in range(n):
    if sum_score_n[i] == max_score:
        result.append(i + 1)

print(*result)