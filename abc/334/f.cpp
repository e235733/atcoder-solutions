#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

double dist(int x1, int y1, int x2, int y2) {
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    return sqrt((double)(dx * dx + dy * dy));
}

using S = double;
S op(S a, S b) { return min(a, b); }
S e() { return 1e18; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, k, sx, sy;
    cin >> n >> k >> sx >> sy;

    vector<int> x(n), y(n);
    rep (i, n) cin >> x[i] >> y[i];
    
    x.push_back(sx); y.push_back(sy);

    double ans = dist(sx, sy, x[0], y[0]);

    vector<double> d(n);
    rep (i, n) {
        double dir = dist(x[i], y[i], x[i+1], y[i+1]);
        double ret = dist(x[i], y[i], sx, sy) + dist(sx, sy, x[i+1], y[i+1]);

        ans += dir;
        d[i] = ret - dir;
    }

    segtree<S, op, e> dp(n+1);

    dp.set(0, 0);

    for (int i = 1; i <= n; i++) {
        double best = dp.prod(max(0, i-k), i);
        dp.set(i, best + d[i-1]);
    }

    ans += dp.get(n);

    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}