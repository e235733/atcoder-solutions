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

    int n, s, k;
    cin >> n >> s >> k;

    int ans = 0;
    rep (_, n) {
        int p, q;
        cin >> p >> q;

        ans += p * q;
    }

    if (ans < s) ans += k;

    cout << ans << '\n';

    return 0;
}