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

    int t;
    cin >> t;
    rep (_, t) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        x = abs(x);
        y = abs(y);

        if (a + b > a * 4 || a + b > b * 4) {
            debug("pattern1");
            if ((x + y) % 2 == 0) {
                cout << min(a, b) * max(x, y) * 2 << '\n';
            }
            else {
                ll result1 = min(a, b) * max(x-1, y) * 2 + a;
                ll result2 = min(a, b) * max(x, y-1) * 2 + b;
                cout << min(result1, result2) << '\n';
            }
        }
        else {
            debug("pattern2");
            ll result = min(a, b) * min(x, y) * 2;
            result += abs(x - y) / 2 * (a + b);
            if ((x - y) % 2 != 0) {
                if (x > y) result += a;
                else result += b;
            }

            cout << result << '\n';
        }
    }

    return 0;
}