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

    ll n, k;
    cin >> n >> k;
    set<ll> A;
    rep (i, n) {
        ll a;
        cin >> a;
        A.insert(a);
    }

    ll ans = k * (k + 1) / 2;
    debug(ans);
    for (ll a : A) {
        if (a > k) break;
        ans -= a;
    }

    cout << ans << '\n';

    return 0;
}