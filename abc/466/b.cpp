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
    cin >> n >> m;
    vector<int> ms(m+1, -1);
    rep (i, n) {
        int c, s;
        cin >> c >> s;
        ms[c] = max(ms[c], s);
    }

    rep (i, m) {
        cout << ms[i+1] << ' ';
    }
    cout << '\n';

    return 0;
}