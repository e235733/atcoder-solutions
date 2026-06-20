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
    vector<pair<int, int>> m(n);
    rep (i, n) {
        int h, l;
        cin >> h >> l;
        m[i] = {l, h};
    }

    sort(m.rbegin(), m.rend());
    debug(m);
    
    map<int, int> mh;
    int pm = 0;
    rep (i, n) {
        pm = max(m[i].second, pm);
        mh[m[i].first] = pm;
    }
    debug(mh);

    int q;
    cin >> q;
    rep (_, q) {
        int t;
        cin >> t;

        cout << mh.upper_bound(t)->second << '\n';
    }

    return 0;
}