#include <bits/stdc++.h>
using namespace std;
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
    vector<ll> L(n), R(n);
    rep (i, n) cin >> L[i] >> R[i];

    vector<ll> u(n+1);
    vector<ll> d(n+1);
    u[0] = 0;
    d[0] = 0;
    rep (i, n) {
        u[i+1] = u[i] + R[i];
        d[i+1] = d[i] + L[i];
    }
    debug(u);
    debug(d);

    if (d[n] > 0 || u[n] < 0) {
        cout << "No" << '\n';
        return 0;
    }

    cout << "Yes" << '\n';
    vector<ll> p(n+1);
    p[0] = 0;
    rep (i, n) {
        p[i+1] = min(u[n-i-1], p[i] - L[n-i-1]);
    }
    debug(p);

    rep (i, n) cout << p[n-i-1] - p[n-i] << ' ';
    cout << '\n';

    return 0;
}