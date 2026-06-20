#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int max_n = 200000;

struct edge {
    int to;
    ll c;
};

vector<vector<edge>> g(max_n+1);

ll mc = 0;
int mn;
void dfs (int cn, int pn, ll sc) {
    if (g[cn].size() == 1 && g[cn][0].to == pn) {
        if (sc > mc) {
            mc = sc;
            mn = cn;
        }
        return;
    }

    for (auto [to, c] : g[cn]) {
        if (to == pn) continue;

        dfs(to, cn, sc+c);
    }
}

ll sum_c = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    rep (_, n-1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});

        sum_c += c;
    }
    debug(n, sum_c);
    
    dfs(1, -1, 0);
    dfs(mn, -1, 0);

    cout << sum_c * 2 - mc << '\n';

    return 0;
}