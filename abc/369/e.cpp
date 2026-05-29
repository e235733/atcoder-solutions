#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct edge {
    int u, v;
    ll c;
};

void dfs(vector<vector<ll>> &pd, vector<edge> &B, ll &mc, ll cc, int n, vector<int> &b, vector<bool> &used, int count, int k, int pb) {
    if (count == k) {
        mc = min(mc, cc + pd[pb][n]);
        return;
    }

    rep (i, k) {
        if (used[i]) {
            continue;
        }
        used[i] = true;

        ll nc1 = cc + pd[pb][B[b[i]].u];
        ll nc2 = cc + pd[pb][B[b[i]].v];
        dfs(pd, B, mc, nc1, n, b, used, count+1, k, B[b[i]].v);
        dfs(pd, B, mc, nc2, n, b, used, count+1, k, B[b[i]].u);

        used[i] = false;
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
    vector<vector<ll>> pd(n+1, vector<ll>(n+1, 1e18));
    vector<edge> B(m+1);
    rep (i, m) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        pd[u][v] = min(pd[u][v], c);
        pd[v][u] = min(pd[v][u], c);
        B[i+1] = {u, v, c};
    }

    for (int i=1; i!=n+1; ++i) {
        vector<vector<ll>> cd = pd;
        for (int s=1; s!=n+1; ++s) {
            for (int g=1; g!=n+1; ++g) {
                ll mc = pd[s][i] + pd[i][g];
                cd[s][g] = min(cd[s][g], mc);
                cd[g][s] = min(cd[g][s], mc);
            }
        }
        pd = cd;
    }
    for (int i=1; i!=n+1; ++i) {
        pd[i][i] = 0;
    }
    debug(pd);

    int q;
    cin >> q;
    rep (_, q) {
        int k;
        cin >> k;

        vector<int> b(k);
        ll bc = 0;
        rep (i, k) {
            cin >> b[i];
            bc += B[b[i]].c;
        }
        debug(k, b);
        vector<bool> used(k, false);
        ll mc = 1e18;
        dfs(pd, B, mc, 0, n, b, used, 0, k, 1);

        cout << mc + bc << '\n';
    }

    return 0;
}