#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<vector<int>> &g, vector<bool> &used, int c) {
    for (int e : g[c]) {
        if (used[e]) {
            continue;
        }

        used[e] = true;
        dfs(g, used, e);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int MV = 1024;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g((n+1)*MV);
    rep (_, m) {
        int a, b, w;
        cin >> a >> b >> w;

        rep (i, MV) {
            g[a*MV+i].push_back(b*MV+(i^w));
        }
    }
    debug(g);

    vector<bool> used((n+1)*MV, false);
    used[MV] = true;
    dfs(g, used, MV);
    debug(used);

    rep (i, MV) {
        if (used[MV*n+i]) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}