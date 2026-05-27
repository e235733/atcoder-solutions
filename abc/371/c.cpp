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

    int n;
    cin >> n;

    vector<vector<bool>> g(n+1, vector<bool>(n+1, false)), h(n+1, vector<bool>(n+1, false));
    int mg;
    cin >> mg;
    rep (_, mg) {
        int u, v;
        cin >> u >> v;

        g[u][v] = true;
        g[v][u] = true; 
    }
    debug(g);
    int mh;
    cin >> mh;
    rep (_, mh) {
        int u, v;
        cin >> u >> v;

        h[u][v] = true;
        h[v][u] = true;
    }
    debug(h);

    vector<vector<int>> c(n+1, vector<int>(n+1));
    rep (i, n) {
        rep (j, n-i-1) {
            int ci;
            cin >> ci;
            c[i+1][i+2+j] = ci;
            c[i+2+j][i+1] = ci;
        }
    }
    debug(c);

    vector<int> p(n+1);
    rep (i, n+1) {
        p[i] = i;
    }

    int min_cost = 1000000000;
    do {
        debug(p);
        int cc = 0;
        for (int i=1; i!=n+1; ++i) {
            for (int j=1; j!=n+1; ++j) {
                if (h[p[i]][p[j]] ^ g[i][j]) {
                    cc += c[p[i]][p[j]];
                }
            }
        }
        min_cost = min(min_cost, cc/2);
        debug(min_cost);
    } while (next_permutation(p.begin()+1, p.end()));

    cout << min_cost << '\n';

    return 0;
}