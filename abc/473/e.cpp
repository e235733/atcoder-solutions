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

    map<int, int> R;
    R[0] = -1;
    vector<pair<int, int>> vp;
    int cr = 0;
    rep (i, n) {
        int a;
        cin >> a;
        cr += a;
        cr %= k;
        if (R.contains(cr)) {
            vp.push_back({i, R[cr]});
        }
        R[cr] = i;
    }
    debug(R);
    //debug(vp);

    sort(vp.begin(), vp.end());
    debug(vp);

    int len = vp.size();
    int ans = 0;
    int c = -1;
    rep (i, len) {
        debug(i, c);
        int r = vp[i].first;
        int l = vp[i].second;
        debug(l, r);
        
        if (r <= c) continue;
        if (l < c) continue;

        ++ans;
        c = r;
    }

    cout << ans << '\n';

    return 0;
}