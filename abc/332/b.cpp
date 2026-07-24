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

    int k, g, m;
    cin >> k >> g >> m;

    int cg = g, cm = m;
    rep (_, k) {
        if (cg == g) cg = 0;
        else if (cm == 0) cm = m;
        else {
            int d = min(g-cg, cm);
            cg += d;
            cm -= d;
        }
    }

    cout << cg << ' ' << cm << '\n';

    return 0;
}