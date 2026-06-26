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

    ll n;
    cin >> n;

    vector<ll> A(n);
    rep (i, n) cin >> A[i];
    sort(A.begin(), A.end());

    ll sa = 0;
    rep (i, n) sa += A[i];
    
    ll count = sa * n * 2;
    debug(count);

    count -= sa * 2;
    debug(count);

    rep (i, n) {
        debug(A[i]);
        ll ng = -1;
        ll ok = n;
        while (ng + 1 < ok) {
            int mid = (ng + ok) / 2;
            if (A[mid] >= 100000000 - A[i]) ok = mid;
            else ng = mid;
        }
        debug(ok);

        if (ok > i) count -= (n - ok) * 100000000;
        else count -= (n - ok - 1) * 100000000;
    }

    cout << count / 2 << '\n';

    return 0;
}