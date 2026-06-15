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

    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> A(n), B(n);
    rep (i, n) cin >> A[i];
    rep (i, n) cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int mca = 0;
    ll sum_a = 0;
    rep (i, n) {
        sum_a += A[i];
        mca++;
        if (sum_a > x) break;
    }
    int mcb = 0;
    ll sum_b = 0;
    rep (i, n) {
        sum_b += B[i];
        mcb++;
        if (sum_b > y) break;
    }

    cout << min(mca, mcb) << '\n';

    return 0;
}