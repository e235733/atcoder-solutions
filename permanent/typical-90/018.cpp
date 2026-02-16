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

    static const double pi = 3.141592653589793;

    double t, l, x, y, q;
    cin >> t >> l >> x >> y >> q;

    double d_x = abs(x);
    cout << fixed << setprecision(10);

    rep (_, q) {
        double e;
        cin >> e;

        // 座標を求める
        double e_y = -l / 2 * sin(e / t * 2 * pi);
        double e_z = l / 2 * (1 - cos(e / t * 2 * pi));
        debug(e_y, e_z);

        // 距離を求める
        double d_y = abs(e_y - y);
        double d_z = abs(e_z);
        double d_xy = sqrt(pow(d_x, 2) + pow(d_y, 2));
        debug(d_xy, d_z);

        double result = atan(d_z / d_xy) / pi * 180;
        cout << result << '\n';
    }

    return 0;
}