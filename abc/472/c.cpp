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

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    rep (i, n) cin >> A[i];

    ll s = 0;
    rep (i, min(n, m)) {
        debug(i, A[i]);
        if (s + A[i] > k) {
            cout << "No" << '\n';
            A[i] = 0;
        }
        else {
            cout << "Yes" << '\n';
            s += A[i];
        }
    }

    if (n <= m) return 0;

    for (int i=m; i!=n; ++i) {
        debug(i, A[i]);
        s -= A[i-m];
        if (s + A[i] > k) {
            cout << "No" << '\n';
            A[i] = 0;
        }
        else {
            cout << "Yes" << '\n';
            s += A[i];
        }
    }

    return 0;
}