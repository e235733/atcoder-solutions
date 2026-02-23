#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

// 深さ優先探索
int dfs(vector<vector<int>> &to, vector<bool> &is_visited, int current_node, int &max_score) {
    is_visited[current_node] = true;
    vector<int> next_to = to[current_node];
    debug(current_node, next_to);
    vector<int> current_scores;
    for (int n : next_to) {
        if (is_visited[n]) {
            continue;
        }
        // 再帰呼び出し
        int score = dfs(to, is_visited, n, max_score);
        debug(n, score);
        current_scores.push_back(score);
    }
    debug(current_node, current_scores);
    // 現在のノードからの最大スコアを求める
    if (current_scores.size() == 0) {
        return 1;
    }
    else if (current_scores.size() == 1) {
        max_score = max(current_scores[0], max_score);
        return current_scores[0] + 1;
    }
    else {
        sort(current_scores.rbegin(), current_scores.rend());
        int current_sum = current_scores[0] + current_scores[1];
        max_score = max(current_sum, max_score);
        return current_scores[0] + 1;
    }
    debug(max_score);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    // 道のグラフ
    vector<vector<int>> to(n+1);
    rep (_, n-1) {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    debug(to);

    int max_score = 0;
    vector<bool> is_visited(n+1, false);
    dfs(to, is_visited, 1, max_score);
    cout << max_score + 1 << '\n';

    return 0;
}