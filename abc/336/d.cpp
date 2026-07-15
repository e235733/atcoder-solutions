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

    vector<int> A(n);
    rep (i, n) cin >> A[i];

    vector<int> B(n+2), C(n+2);
    B[0] = 0, C[n+1] = 0;

    rep (i, n) {
        B[i+1] = min(B[i]+1, A[i]);
    }
    rep (i, n) {
        C[n-i] = min(C[n-i+1]+1, A[n-i-1]);
    }
    debug(B);
    debug(C);

    int ans = 0;
    rep (i, n) {
        ans = max(ans, min(B[i+1], C[i+1]));
    }

    cout << ans << '\n';

    return 0;
}