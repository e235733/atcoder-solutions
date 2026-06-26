#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using fp = modint998244353;
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

    fp sa;
    rep (i, n) {
        sa += A[i];
    }

    vector<fp> p10(11);
    p10[0] = 1;
    rep (i, 10) {
        p10[i+1] = p10[i] * 10;
    }

    vector<int> ad(n);
    map<int, int> dc;
    rep (i, n) {
        int la = A[i];
        int d = 0;
        while (la != 0) {
            la /= 10;
            d++;
        }
        ad[i] = d;
        dc[d]++;
    }
    debug(dc);

    fp ans = 0;
    rep (i, n) {
        sa -= A[i];
        ans += sa;
        dc[ad[i]]--;
        for (auto [d, c] : dc) {
            ans += A[i] * p10[d] * c;
        }
    }

    cout << ans.val() << '\n';

    return 0;
}