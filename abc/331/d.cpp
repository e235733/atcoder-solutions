#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

ll cs(vector<vector<ll>> &S, ll ca, ll n, ll r, ll c) {
    ll mr = r / n;
    ll mc = c / n;

    ll res = mr * mc * ca;

    ll rr = r % n;
    ll rc = c % n;
    res += S[rr][n] * mc;
    res += S[n][rc] * mr;
    
    res += S[rr][rc];

    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ll n, q;
    cin >> n >> q;
    vector P(n, vector<char>(n));
    rep (i, n) {
        rep (j, n) {
            cin >> P[i][j];
        }
    }

    vector S(n+1, vector<ll>(n+1, 0));
    ll ca = 0;
    rep (i, n) {
        rep (j, n) {
            if (P[i][j] == 'B') {
                ++S[i+1][j+1];
                ++ca;
            }
        }
    }
    rep (i, n) {
        rep (j, n) {
            S[i+1][j+1] += S[i+1][j];
        }
    }
    rep (i, n) {
        rep (j, n) {
            S[i+1][j+1] += S[i][j+1];
        }
    }
    //debug(S);

    rep (_, q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ++c, ++d;

        ll ans = cs(S, ca, n, c, d) - cs(S, ca, n, c, b) - cs(S, ca, n, a, d) + cs(S, ca, n, a, b);

        cout << ans << '\n';
    }

    return 0;
}