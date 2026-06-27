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

    vector<string> s(n), t(n);
    rep (i, n) cin >> s[i];
    rep (i, n) cin >> t[i];

    rep (i, n) {
        rep (j, n) {
            if (s[i][j] != t[i][j]) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }

    return 0;
}