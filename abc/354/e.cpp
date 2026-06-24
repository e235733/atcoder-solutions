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
    vector<int> A(n), B(n);
    rep (i, n) cin >> A[i] >> B[i];

    vector<int> dp(1 << n, -1);
    dp[0] = 0;

    for (int i=1; i!=1<<n; ++i) {
        bool f = false;
        rep (j, n) {
            for (int k=j+1; k!=n; ++k) {
                if (((i >> j) & 1) && ((i >> k) & 1)) {
                    if ((A[j] == A[k] || B[j] == B[k]) && dp[i ^ (1<<j) ^ (1<<k)] == 0) {
                        f = true;
                    }
                }
            }
        }
        dp[i] = f;
    }
    debug(dp);

    cout << (dp.back() ? "Takahashi" : "Aoki") << '\n';

    return 0;
}