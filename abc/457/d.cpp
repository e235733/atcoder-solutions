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

    ll n, k;
    cin >> n >> k;
    debug(n, k);
    vector<ll> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    debug(A);

    ll ok = 1;
    ll ng = 2000000000000000001;
    while (ng > ok + 1) {
        ll mid = (ok + ng) / 2;
        __int128_t count = 0;
        rep (i, n) {
            if (A[i] < mid) {
                if ((mid - A[i]) % (i + 1) == 0) {
                    count += (mid - A[i]) / (i + 1);
                }
                else {
                    count += (mid - A[i]) / (i + 1) + 1;
                }
            }
            if (count > k) {
                break;
            }
        }
        if (count > k) {
            ng = mid;
        }
        else {
            ok = mid;
        }
    }
    debug(ok, ng);

    cout << ok << '\n';

    return 0;
}