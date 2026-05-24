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

    int n, h, m;
    cin >> n >> h >> m;

    vector<map<int, int>> dp(n+1);
    dp[0][m] = h;
    rep (i, n) {
        int a, b;
        cin >> a >> b;

        for (auto [cm, ch] : dp[i]) {
            if (cm >= b) {
                if (dp[i+1].contains(cm-b)) {
                    dp[i+1][cm-b] = max(dp[i+1][cm-b], ch);
                }
                else {
                    dp[i+1][cm-b] = ch;
                }
            }
            if (ch >= a) {
                if (dp[i+1].contains(cm)) {
                    dp[i+1][cm] = max(dp[i+1][cm], ch-a);
                }
                else {
                    dp[i+1][cm] = ch - a;
                }
            }
        }
        if (!dp[i+1].size()) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';

    return 0;
}