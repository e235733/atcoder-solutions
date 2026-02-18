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

    int n;
    cin >> n;

    ll divider = 1;
    rep (_, 9) {
        divider *= 10;
    }
    divider += 7;
    debug(divider);

    // dp で求める
    vector<ll> dp(6);
    rep (i, 6) {
        cin >> dp[i];
    }

    rep (_, n-1) {
        ll sum = 0;
        rep (i, 6) {
            ll a;
            cin >> a;
            sum += a;
        }
        debug(sum);
        rep (i, 6) {
            dp[i] *= sum;
            dp[i] %= divider;
        }
        debug(dp);
    }

    ll result = 0;
    rep (i, 6) {
        result += dp[i];
    }
    result %= divider;

    cout << result << '\n';

    return 0;
}