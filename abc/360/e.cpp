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

    ll n_raw, k;
    cin >> n_raw >> k;
    
    modint998244353 n = modint998244353(n_raw);
    
    modint998244353 d = 1;
    modint998244353 p = modint998244353(2 * (n - 1)) / n / n;
    modint998244353 q = modint998244353(2) / n / n;
    rep (_, k) {
        d = d * (1 - p) + (1 - d) * q;
    }
    
    ll result = (d + (n + 2) / 2 * (1 - d)).val();
    cout << result << '\n';

    return 0;
}