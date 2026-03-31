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

    const ll mod = 1e9 + 7;

    int k;
    cin >> k;

    // 9 の倍数でなければ成立しない
    if (k % 9 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    // dp で求める
    vector<ll> dp(k+1);
    dp[0] = 1;
    rep (i, k) {
        // 最大の桁に入りうる数値
        int b = min(i+1, 9);
        debug(i+1);
        rep (j, b) {
            dp[i+1] += dp[i-j];
        }
        dp[i+1] %= mod;
    }
    debug(dp);

    cout << dp[k] << '\n';

    return 0;
}