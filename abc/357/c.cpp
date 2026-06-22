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
    cin >> n;

    vector<string> t = {"#"};
    rep (i, n) {
        int m = t.size();
        vector<string> s(m*3, "");
        rep (j, 3) rep(k, 3) rep(l, m) {
            s[m*j+l] += t[l];
        }
        rep (j, m) rep (k, m) {
            s[m+j][m+k] = '.';
        }
        debug(s);
        t = s;
    }

    for (string s : t) {
        cout << s << '\n';
    }

    return 0;
}