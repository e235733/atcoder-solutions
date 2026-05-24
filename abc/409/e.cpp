#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct edge {
    int to;
    int w;
};

ll dfs(vector<vector<edge>> &g, vector<int> &x, int pn, int cn, ll &sc) {
    ll cx = x[cn];
    for (auto [to, w] : g[cn]) {
        if (to == pn) {
            continue;
        }

        ll nx = dfs(g, x, cn, to, sc);
        cx += nx;
        sc += abs(nx) * w;
    }

    return cx;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<int> x(n+1);
    rep (i, n) {
        cin >> x[i+1];
    }

    vector<vector<edge>> g(n+1);
    rep (_, n-1) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ll sc = 0;
    dfs(g, x, -1, 1, sc);

    cout << sc << '\n';

    return 0;
}