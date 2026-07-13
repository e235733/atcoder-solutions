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

    ll ma = 0LL;
    for (int i=n-1; i!=-1; --i) {
        ma = max(ma-A[i], 0LL);
    }
    debug(ma);

    rep (i, n) {
        ma += A[i];
    }

    cout << ma << '\n';

    return 0;
}