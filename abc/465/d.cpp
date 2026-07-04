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
        ll x, y, k;
        cin >> x >> y >> k;

        int count = 0;
        while (x != y) {
            if (x > y) {
                x /= k;
            }
            else {
                y /= k;
            }
            count++;
        }

        cout << count << '\n';
    }

    return 0;
}