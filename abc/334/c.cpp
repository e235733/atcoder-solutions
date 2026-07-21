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

    int n, k;
    cin >> n >> k;

    vector<int> A(k);
    rep (i, k) cin >> A[i];

    if (k % 2 == 0) {
        int ans = 0;
        rep (i, k/2) {
            ans += A[i*2+1] - A[i*2];
        }

        cout << ans << '\n';
    }
    else {
        vector<int> B(k/2+1), C(k/2+1);
        B[0] = 0;
        rep (i, k/2) {
            B[i+1] = B[i] + A[i*2+1] - A[i*2];
        }
        debug(B);
        C[k/2] = 0;
        rep (i, k/2) {
            C[k/2-i-1] = C[k/2-i] + A[k-1-i*2] - A[k-1-i*2-1];
        }
        debug(C);

        int ans = 1<<30;
        rep (i, k/2+1) {
            ans = min(B[i] + C[i], ans);
        }

        cout << ans << '\n';
    }

    return 0;
}