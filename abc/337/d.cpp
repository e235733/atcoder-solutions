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

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> S(h);
    rep (i, h) cin >> S[i];

    int ans = 1<<30;

    if (k <= w) {
        rep (i, h) {
            int o = 0, x = 0;
            rep (j, k) {
                if (S[i][j] == 'o') ++o;
                else if (S[i][j] == 'x') ++x;
            }
            if (x == 0) ans = min(ans, k-o);

            rep (j, w-k) {
                if (S[i][j] == 'o') --o;
                else if (S[i][j] == 'x') --x;
                if (S[i][j+k] == 'o') ++o;
                else if (S[i][j+k] == 'x') ++x;

                if (x == 0) ans = min(ans, k-o);
            }
        }
    }
    if (k <= h) {
        rep (j, w) {
            int o = 0, x = 0;
            rep (i, k) {
                if (S[i][j] == 'o') ++o;
                else if (S[i][j] == 'x') ++x;
            }
            if (x == 0) ans = min(ans, k-o);

            rep (i, h-k) {
                if (S[i][j] == 'o') --o;
                else if (S[i][j] == 'x') --x;
                if (S[i+k][j] == 'o') ++o;
                else if (S[i+k][j] == 'x') ++x;

                if (x == 0) ans = min(ans, k-o);
            }
        }
    }

    if (ans == 1<<30) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}