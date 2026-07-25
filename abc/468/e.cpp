#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
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

    vector<mint> S(n+1);
    S[0] = 0;
    rep (i, n) {
        S[i+1] = S[i] + A[i];
    }

    mint ans = 0;
    int m = n / 2;
    if (n % 2 == 1) ++m;
    mint ps = 0;
    rep (i, m) {
        mint cs = S[n-i] - S[i] + ps;
        mint avg = cs / (i + 1);
        ans += avg;
        ps = cs;
    }

    ps = 0;
    rep (i, n/2) {
        mint cs = S[n-i] - S[i] + ps;
        mint avg = cs / (n - i);
        ans += avg;
        ps = cs;
    }

    cout << ans.val() << '\n';

    return 0;
}