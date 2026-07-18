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

    int t;
    cin >> t;
    rep (_, t) {
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        ll xpq = qx - px, ypq = qy - py, xrs = sx - rx, yrs = sy - ry;

        if (xpq * yrs != ypq * xrs) cout << "Yes" << '\n';
        else {
            ll xh = rx + sx - px - qx, yh = ry + sy - py - qy;
            if (xpq * xh + ypq * yh == 0) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }

    return 0;
}