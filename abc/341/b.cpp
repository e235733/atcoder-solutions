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

    int n;
    cin >> n;
    vector<ll> A(n);
    rep (i, n) cin >> A[i];

    rep (i, n-1) {
        ll s, t;
        cin >> s >> t;
        A[i+1] += A[i] / s * t;
    }

    cout << A[n-1] << '\n';

    return 0;
}