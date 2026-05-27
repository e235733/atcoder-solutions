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

    vector<int> x(n);
    rep (i, n) {
        cin >> x[i];
    }
    vector<ll> p(n);
    rep (i, n) {
        cin >> p[i];
    }

    map<int, ll> pf;
    ll pp = 0;
    pf[1000000001] = 0;
    rep (i, n) {
        pp += p[n-i-1];
        pf[x[n-i-1]] = pp;
    }
    pf[-1000000000] = pp;

    int q;
    cin >> q;
    rep (_, q) {
        int l, r;
        cin >> l >> r;

        cout << pf.lower_bound(l)->second - pf.upper_bound(r)->second << '\n';
    }

    return 0;
}