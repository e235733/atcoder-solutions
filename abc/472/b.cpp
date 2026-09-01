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
    vector<int> L(n);
    rep (i, n) cin >> L[i];

    int ans = 1<<30;
    rep (i, n-1) {
        int l = 0;
        rep (j, i+1) {
            l += L[j];
        }
        int r = 0;
        for (int k=i+1; k!=n; ++k) {
            r += L[k];
        }
        ans = min(ans, abs(l-r));
    }

    cout << ans << '\n';

    return 0;
}