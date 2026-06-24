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

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll dx = x2 - x1;
    ll dy = y2 - y1;
    ll lx = dx - dx / 4 * 4;
    debug(dx, lx);

    ll ans = (dx - lx) * dy;
    debug(ans);
    rep (i, lx) {
        ll xm4 = (x1 + dx - lx + i + (1 << 30)) % 4;
        debug(i, xm4);
        if (xm4 == 0) {
            ans += dy / 2 * 3;
            if (dy % 2 == 1) {
                if (y2 % 2 != 0) ans += 2;
                else ans += 1;
            }
        }
        else if (xm4 == 1) {
            ans += dy / 2 * 3;
            if (dy % 2 == 1) {
                if(y2 % 2 != 0) ans += 1;
                else ans += 2;
            }
        }
        else if (xm4 == 2) {
            ans += dy / 2;
            if (dy % 2 == 1) {
                if (y2 % 2 == 0) ans++;
            }
        }
        else {
            ans += dy / 2;
            if (dy % 2 == 1) {
                if (y2 % 2 != 0) ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}