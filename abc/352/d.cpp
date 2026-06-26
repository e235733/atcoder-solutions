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
    vector<int> Q(n);
    rep (i, n) {
        int p;
        cin >> p;
        Q[p-1] = i;
    }

    set<int> P;
    rep (i, k) {
        P.insert(Q[i]);
    }

    auto ite = P.end();
    ite--;
    int ans = *ite - *P.begin();
    rep (i, n-k) {
        P.erase(Q[i]);
        P.insert(Q[k+i]);
        auto ite = P.end();
        ite--;
        ans = min(ans, *ite - *P.begin());
    }

    cout << ans << '\n';

    return 0;
}