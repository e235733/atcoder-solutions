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

    int n, q;
    cin >> n >> q;
    vector<ll> R(n);
    rep (i, n) cin >> R[i];

    sort(R.begin(), R.end());
    debug(R);

    vector<ll> S(n+1);
    S[0] = 0;
    rep (i, n) {
        S[i+1] = S[i] + R[i];
    }
    debug(S);

    rep (_, q) {
        ll x;
        cin >> x;

        ll ok = 0;
        ll ng = n+1;
        while (ok + 1 < ng) {
            ll mid = (ok + ng) / 2;
            if (S[mid] <= x) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }

        cout << ok << '\n';
    }

    return 0;
}