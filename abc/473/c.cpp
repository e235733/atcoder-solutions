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

    vector<int> C(k+1, 0);
    rep (i, n) {
        int a;
        cin >> a;
        ++C[a];
    }

    int mc = *max_element(C.begin(), C.end());
    debug(mc);

    int ans = 0;
    rep (i, k) {
        if (C[i+1] >= mc - 1) {
            ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}