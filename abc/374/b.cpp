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

    string s, t;
    cin >> s >> t;

    int ls = s.size();
    int lt = t.size();
    int ml = min(ls, lt);

    rep (i, ml) {
        if (s[i] != t[i]) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    if (ls == lt) {
        cout << 0 << '\n';
    }
    else {
        cout << ml + 1 << '\n';
    }

    return 0;
}