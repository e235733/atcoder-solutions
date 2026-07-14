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

    int sx = 0, sy = 0;
    rep (i, n) {
        int x, y;
        cin >> x >> y;
        sx += x;
        sy += y;
    }

    if (sx > sy) {
        cout << "Takahashi" << '\n';
    }
    else if (sy > sx) {
        cout << "Aoki" << '\n';
    }
    else {
        cout << "Draw" << '\n';
    }

    return 0;
}