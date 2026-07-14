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
    vector<ll> X(m);
    rep (i, m) cin >> X[i];

    vector<ll> imos(n, 0);
    rep (i, m-1) {
        ll l = min(X[i], X[i+1]);
        ll r = max(X[i], X[i+1]);

        ll ic = r - l;
        ll oc = l - r + n;
        imos[0] += ic;
        imos[l-1] += -ic + oc;
        imos[r-1] += -oc + ic;
    }
    debug(imos);

    rep (i, n-1) {
        imos[i+1] += imos[i];
    }
    debug(imos);

    cout << *min_element(imos.begin(), imos.end()) << '\n';

    return 0;
}