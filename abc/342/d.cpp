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
    map<int, int> ac;
    rep (_, n) {
        int a;
        cin >> a;

        int mi = 1;
        for (int i=2; i*i<=a; ++i) {
            if (a % (i*i) == 0) {
                mi = i;
            }
        }
        ++ac[a/mi/mi];
    }
    debug(ac);

    ll ans = 0;
    for (auto [a, c] : ac) {
        if (a == 0) {
            ans += 1LL * ((n-1) + (n-c)) * c / 2;
            continue;
        }

        ans += 1LL * c * (c - 1) / 2;
    }
    cout << ans << '\n';

    return 0;
}