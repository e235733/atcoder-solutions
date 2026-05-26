#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct edge {
    int to;
    ll weight;
};

void dfs(vector<vector<edge>> &g, vector<bool> &used, vector<ll> &result, int ce) {
    for (auto [ne, weight] : g[ce]) {
        if (used[ne]) {
            continue;
        }
        used[ne] = true;
        result[ne] = result[ce] + weight;
        dfs(g, used, result, ne);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n+1);
    rep (i, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, -w});
    }

    vector<bool> used(n+1, false);
    vector<ll> result(n+1);
    for (int i=1; i!=n+1; ++i) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        result[i] = 0;
        dfs(g, used, result, i);
    }

    for (int i=1; i!=n+1; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';

    return 0;
}