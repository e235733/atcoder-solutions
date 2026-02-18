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

    int n, l;
    cin >> n >> l;

    if (n < l) {
        cout << 1 << '\n';
        return 0;
    }

    int divider = 1;
    rep (_, 9) {
        divider *= 10;
    }
    divider += 7;
    debug(divider);

    vector<int> dp(n+1);
    rep (i, l) {
        dp[i] = 1;
    }
    for (int i=l; i!=n+1; ++i) {
        dp[i] = (dp[i-1] + dp[i-l]) % divider;
    }

    cout << dp.back() << '\n';

    return 0;
}