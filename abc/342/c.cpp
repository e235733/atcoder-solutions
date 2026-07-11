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
    string s;
    cin >> n >> s;

    int q;
    cin >> q;
    vector<char> T(26);
    rep (i, 26) T[i] = (char)('a' + i);
    rep (_, q) {
        char c, d;
        cin >> c >> d;

        rep (i, 26) {
            if (T[i] == c) T[i] = d;
        }
    }
    debug(T);

    rep (i, n) {
        cout << T[s[i]-'a'];
    }
    cout << '\n';

    return 0;
}