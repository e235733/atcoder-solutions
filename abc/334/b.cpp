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

    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    ll lk = (l - a) / m;
    if (l - a > 0 && (l - a) % m != 0) ++lk;
    
    ll rk = (r - a) / m + 1;
    if (r - a < 0 && (r - a) % m != 0) --rk;

    debug(lk, rk);

    cout << rk - lk << '\n';

    return 0;
}