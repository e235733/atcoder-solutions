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

    int INF = 1 << 30;

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n), B(n);
    rep (i, n) cin >> A[i] >> B[i];

    vector dp(n+1, vector(n+1, vector<int>(x+1, INF)));
    dp[0][0][0] = 0;
    rep (i, n) {
        rep (j, n) {
            rep (k, x) {
                dp[i+1][j][k] = min(dp[i][j][k], dp[i+1][j][k]);
                if (k + A[i] <= x) {
                    dp[i+1][j+1][k+A[i]] = min(dp[i][j][k]+B[i], dp[i+1][j+1][k+A[i]]);
                }
            }
        }
    }
    debug(dp);

    rep (j, n+1) {
        rep (k, x+1) {
            if (dp[n][n-j][k] <= y) {
                cout << min(n-j+1, n) << '\n';
                return 0;
            }
        }
    }

    return 0;
}