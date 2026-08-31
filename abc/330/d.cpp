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
    vector<string> S(n);
    rep (i, n) cin >> S[i];

    vector<ll> cr(n, 0), cc(n, 0);
    rep (i, n) {
        rep (j, n) {
            if (S[i][j] == 'o') {
                ++cr[i];
                ++cc[j];
            }
        }
    }

    ll ans = 0;
    rep (i, n) {
        rep (j, n) {
            if (S[i][j] == 'o') {
                ans += (cr[i] - 1) * (cc[j] - 1);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}