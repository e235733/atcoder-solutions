#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
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
    vector<ll> A(n);
    rep (i, n) cin >> A[i];

    if (k == 1) {
        mint ans = 0;
        rep (i, n) {
            ans += (mint)A[i] * A[i];
        }
        cout << ans.val() << '\n';
        return 0;
    }

    mint f = 0;
    rep (i, n) {
        f += A[i] * A[i];
    }
    for (ll i=n-1; i!=n-k; --i) {
        f *= i;
    }
    for (ll i=k-1; i!=0; --i) {
        f /= i;
    }
    debug(f.val());

    mint s = 0;
    rep (i, n) s += A[i];
    mint g = 0;
    rep (i, n) {
        g += A[i] * (s - A[i]);
    }
    for (ll i=n-2; i!=n-k; --i) {
        g *= i;
    }
    for (ll i=k-2; i!=0; --i) {
        g /= i;
    }
    debug(g.val());
    
    cout << (f + g).val() << '\n';

    return 0;
}