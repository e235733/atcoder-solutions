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

    dsu d(n);
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        d.merge(a, b);
    }

    vector<bool> leader(n, false);
    ll ans = -m;
    rep (i, n) {
        int l = d.leader(i);
        if (leader[l]) continue;
        leader[l] = true;

        ll c = d.size(l);
        ans += c * (c - 1) / 2;
    }

    cout << ans << '\n';

    return 0;
}