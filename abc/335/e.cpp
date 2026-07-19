#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    vector<int> a(n);
    rep (i, n) cin >> a[i];

    dsu uf(n);
    vector<vector<pair<int,int>>> vp(200005);

    rep (i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (a[u] > a[v]) swap(u, v);

        if (a[u] == a[v]) {
            uf.merge(u, v);
        } else {
            vp[a[u]].push_back({u, v});
        }
    }

    vector<int> dp(n, -1e9);

    dp[uf.leader(0)] = 1;

    for (auto &edges : vp) {
        for (auto [u, v] : edges) {
            u = uf.leader(u);
            v = uf.leader(v);

            if (dp[u] > 0) {
                dp[v] = max(dp[v], dp[u]+1);
            }
        }
    }

    cout << max(0, dp[uf.leader(n-1)]) << '\n';

    return 0;
}