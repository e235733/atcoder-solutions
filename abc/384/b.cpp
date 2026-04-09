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

    int n, r;
    cin >> n >> r;

    rep (_, n) {
        int d, a;
        cin >> d >> a;
        if (d == 1) {
            if (r >= 1600 && r < 2800) {
                r += a;
            }
        }
        else if (d == 2) {
            if (r >= 1200 && r < 2400) {
                r += a;
            }
        }
    }

    cout << r << '\n';

    return 0;
}