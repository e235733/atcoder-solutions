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

    int n;
    cin >> n;

    rep (x, n+1) {
        rep (y, n+1) {
            if (x + y > n) break;
            rep (z, n+1) {
                if (x + y + z > n) break;

                cout << x << ' ' << y << ' ' << z << '\n';
            }
        }
    }

    return 0;
}