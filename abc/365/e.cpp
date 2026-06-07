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
    vector<int> A(n);
    rep (i, n) cin >> A[i];

    // 累積 xor
    vector<int> S(n+1);
    S[0] = 0;
    rep (i, n) S[i+1] = S[i] ^ A[i];
    debug(S);

    ll ans = 0;
    rep (k, 27) {
        int one = 0;
        rep (i, n+1) if (S[i] >> k & 1) one++;
        ans += 1LL * one * (n + 1 - one) * (1 << k);
    }

    rep (i, n) ans -= A[i];
    cout << ans << '\n';

    return 0;
}