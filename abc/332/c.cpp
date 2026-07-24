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

    int n, m;
    string S;
    cin >> n >> m >> S;

    int ms = 0;
    int mp = 0;
    int cs = 0;
    int cp = 0;
    rep (i, n) {
        if (S[i] == '0') {
            ms = max(ms, cs);
            mp = max(mp, cp);
            cs = 0, cp = 0;
        }
        else if (S[i] == '1') {
            ++cs;
        }
        else if (S[i] == '2') {
            ++cs;
            ++cp;
        }
    }
    ms = max(ms, cs);
    mp = max(mp, cp);

    cout << mp + max(0, ms - mp - m) << '\n';

    return 0;
}