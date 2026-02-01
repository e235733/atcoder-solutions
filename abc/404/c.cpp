#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    // 無向グラフ
    vector<vector<int>> g(n+1);
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    debug(g);

    // 全ての点から２本の辺が出ていることを確かめる
    rep (i, n) {
        if (g[i+1].size() != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    // 点1から調べ、元に戻ってくるまでに全点を探索できたか調べる
    vector<bool> is_visited(n+1, false);
    int current_node = g[1][0];
    is_visited[1] = true;
    is_visited[current_node] = true;
    while (current_node != 1) {
        debug(current_node);
        int next_node = 1;
        for (int n : g[current_node]) {
            // 未訪問の点へ移動
            if (!is_visited[n]) {
                next_node = n;
                break;
            }
        }
        debug(next_node);
        is_visited[next_node] = true;
        current_node = next_node;
    }
    debug(is_visited);

    // is_visited が全て true か検査
    rep (i, n) {
        if (!is_visited[i+1]) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;

    return 0;
}