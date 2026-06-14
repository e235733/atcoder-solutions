#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<vector<int>> &g, vector<int> &nc, int c, int p) {
    nc[c] = 1;
    for (int n : g[c]) {
        if (n == p) {
            continue;
        }

        dfs(g, nc, n, c);
        nc[c] += nc[n];
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
    vector<vector<int>> g(n+1);
    vector<int> a(n-1), b(n-1);
    rep (i, n-1) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    debug(g);

    vector<int> nc(n+1);
    dfs(g, nc, 1, -1);
    debug(nc);

    ll result = 0;
    rep (i, n-1) {
        int c = min(nc[a[i]], nc[b[i]]);
        result += 1LL * c * (n - c);
    }
    cout << result << '\n';

    return 0;
}