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

    string t;
    cin >> t;
    int len = t.size();

    int n;
    cin >> n;
    vector<int> A(n);
    vector S(n, vector<string>());
    rep (i, n) {
        cin >> A[i];
        rep (j, A[i]) {
            string s;
            cin >> s;
            S[i].push_back(s);
        }
    }
    
    vector dp(n+1, vector<int>(len+1, 1<<30));
    dp[0][0] = 0;

    rep (i, n) {
        rep (j, len+1) {
            if (dp[i][j] == 1<<30) continue;
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            rep (k, A[i]) {
                int ls = S[i][k].size();
                if (j + ls > len) continue;

                bool ok = true;
                rep (l, ls) {
                    if (S[i][k][l] != t[l+j]) {
                        ok = false;
                        break;
                    } 
                }
                if (!ok) continue;
                dp[i+1][j+ls] = min(dp[i+1][j+ls], dp[i][j] + 1);
            }
        }
    }
    debug(dp);

    if (dp[n][len] == 1<<30) cout << -1 << '\n';
    else cout << dp[n][len] << '\n';

    return 0;
}