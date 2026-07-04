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

    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    vector<int> c(24, y);
    for (int i=l; i!=r; ++i) {
        c[i] = x;
    }

    int ans = 0;
    for (int i=a; i!=b; ++i) {
        ans += c[i];
    }

    cout << ans << '\n';

    return 0;
}