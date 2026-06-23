#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int inf = 1 << 30;

int n;
vector<int> l(500000, inf), r(500000, inf);

map<int, int> nl, nr;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;

    rep (i, n) cin >> l[i] >> r[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    nl[-1] = 0;
    int cnl = 0;
    rep (i, n) {
        cnl++;
        nl[l[i]] = cnl;
    }
    debug(nl);

    nr[-1] = 0;
    int cnr = 0;
    rep (i, n) {
        cnr++;
        nr[r[i]] = cnr;
    }
    debug(nr);

    ll ans = 1LL * n * (n - 1);
    rep (i, n) {
        debug(r[i]);
        auto itl = nl.upper_bound(r[i]);
        itl--;
        ans -= n - itl->second;

        debug(l[i]);
        auto itr = nr.lower_bound(l[i]);
        itr--;
        debug(itr->second);
        ans -= itr->second;
    }

    cout << ans / 2 << '\n';

    return 0;
}