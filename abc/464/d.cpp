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

    int t;
    cin >> t;
    rep (_, t) {
        int n;
        string s;
        cin >> n >> s;
        
        ll x0;
        cin >> x0;
        ll dps = 0;
        ll dpr = 0;
        if (s[0] == 'S') {
            dpr -= x0;
        }
        else {
            dps -= x0;
        }

        vector<ll> X(n-1), Y(n-1);
        rep (i, n-1) cin >> X[i];
        rep (i, n-1) cin >> Y[i];
        debug(X);
        debug(Y);

        rep (i, n-1) {
            debug(i, dps, dpr);
            debug(s[i+1]);
            ll ndps = max(dps, dpr + Y[i]);
            ll ndpr = max(dps, dpr);
            if (s[i+1] == 'S') ndpr -= X[i];
            else ndps -= X[i];

            dps = ndps;
            dpr = ndpr;
        }

        cout << max(dps, dpr) << '\n';
    }

    return 0;
}