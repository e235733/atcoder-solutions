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

    string s, t;
    cin >> s >> t;

    int len_s = s.size();

    int j = 0;
    rep (i, len_s) {
        if (j == 3) break;
        if (s[i] - 'a' == t[j] - 'A') ++j;
    }

    if (j == 3) cout << "Yes" << '\n';
    else if (j == 2) {
        if (t[2] == 'X') cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    else cout << "No" << '\n';

    return 0;
}