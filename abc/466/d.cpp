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

    int n, m;
    cin >> n >> m;
    vector<int> R(m), C(m);
    rep (i, m) cin >> R[i] >> C[i];

    ll ans = 0;
    set<int> rr, rc;
    for (int i=m-1; i!=-1; --i) {
        if (rr.contains(R[i]) || rc.contains(C[i]));
        else ++ans;

        rr.insert(R[i]);
        rc.insert(C[i]);
    }
    debug(rr);
    debug(rc);
    
    cout << ans << '\n';

    return 0;
}