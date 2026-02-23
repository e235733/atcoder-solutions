#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

// 深さ優先探索
void dfs(vector<vector<int>> &g, vector<int> &odd_nodes, vector<int> &even_nodes, int current_node, int prev_node, bool is_odd) {
    if (is_odd) {
        odd_nodes.push_back(current_node);
    }
    else {
        even_nodes.push_back(current_node);
    }
    vector<int> next_nodes = g[current_node];
    bool is_next_odd = !is_odd;
    for (int n : next_nodes) {
        if (n != prev_node) {
            dfs(g, odd_nodes, even_nodes, n, current_node, is_next_odd);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    // 無向グラフ
    vector<vector<int>> g(n+1);
    rep (_, n-1) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    debug(g);

    // 頂点 1 からはじめ、奇数番目と偶数番目にたどる頂点に分ける
    vector<int> odd_nodes, even_nodes;
    dfs(g, odd_nodes, even_nodes, 1, 0, true);
    if ((int)odd_nodes.size() >= n / 2) {
        rep (i, n/2) {
            cout << odd_nodes[i] << ' ';
        }
    }
    else {
        rep (i, n/2) {
            cout << even_nodes[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}