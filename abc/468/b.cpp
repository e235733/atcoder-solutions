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

    int m, d;
    string s;
    cin >> m >> d >> s;

    rep (i, m) {
        if (s[i] == 'G') {
            rep (j, d) {
                if (i-j-1 == -1) break;

                if (s[i-j-1] == 'G') continue;

                s[i-j-1] = '#';
            }
            rep (j, d) {
                if (i+j+1 == m) break;

                if (s[i+j+1] == 'G') continue;

                s[i+j+1] = '#';
            }
        }
    }
    debug(s);

    int ans = 0;
    rep (i, m) {
        if (s[i] == '.') ++ans;
    }

    cout << ans << '\n';

    return 0;
}