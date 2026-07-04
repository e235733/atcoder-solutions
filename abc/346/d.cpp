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
    string s;
    cin >> n >> s;
    vector<ll> C(n);
    rep (i, n) cin >> C[i];

    vector<ll> so(n+1), se(n+1);
    so[0] = 0;
    se[0] = 0;
    rep (i, n) {
        if (s[i] == '0') {
            if (i % 2) {
                so[i+1] = so[i];
                se[i+1] = se[i] + C[i];
            }
            else {
                so[i+1] = so[i] + C[i];
                se[i+1] = se[i];
            }
        }
        else {
            if (i % 2) {
                so[i+1] = so[i] + C[i];
                se[i+1] = se[i];
            }
            else {
                so[i+1] = so[i];
                se[i+1] = se[i] + C[i];
            }
        }
    }
    debug(so);
    debug(se);

    ll mc = 1LL << 60;
    rep (i, n-1) {
        mc = min(mc, so[i+1] + se[n] - se[i+1]);
        mc = min(mc, se[i+1] + so[n] - so[i+1]);
    }

    cout << mc << '\n';

    return 0;
}