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

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    ll dx = abs(tx - sx);
    ll dy = abs(ty - sy);

    if (dx > dy) {
        ll ans = dy;
        if (tx > sx) {
            if ((sx + dy) % 2 == (sy + dy) % 2) ans += (dx - dy) / 2;
            else ans += (dx - dy + 1) / 2;
        }
        else {
            if ((sx + dy) % 2 == (sy + dy) % 2) ans += (dx - dy + 1) / 2;
            else ans += (dx - dy) / 2;
        }
        cout << ans << '\n';
    }
    else cout << dy << '\n';

    return 0;
}