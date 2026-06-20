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
    char x;
    cin >> n >> x;

    vector<string> s(n);
    rep (i, n) cin >> s[i];

    vector<bool> ok(5, false);
    rep (i, n) {
        rep (j, 5) {
            if (s[i][j] == 'o') ok[j] = true;
        }
    }

    if (ok[x-'A']) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}