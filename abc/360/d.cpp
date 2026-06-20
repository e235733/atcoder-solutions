#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

ll INF = 1LL << 60;

vector<ll> X(200001);

vector<ll> M, P;
map<ll, ll> cm, cp;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ll n, t;
    string s;
    cin >> n >> t >> s;
    rep (i, n) cin >> X[i];
    rep (i, n) {
        if (s[i] == '1') P.push_back(X[i]);
        else if (s[i] == '0') M.push_back(X[i]);
    }
    sort(P.begin(), P.end());
    sort(M.begin(), M.end());

    cp[-INF] = 0;
    ll pcp = 0;
    for (ll p : P) {
        pcp++;
        cp[p] = pcp;
    }
    debug(cp);

    cm[-INF] = 0;
    ll pcm = 0;
    for (ll m : M) {
        pcm++;
        cm[m] = pcm;
    }
    debug(cm);

    ll result = 0;
    rep (i, n) {
        debug(s[i], X[i]);
        if (s[i] == '1') {
            auto itr = cm.upper_bound(min(INF-1, X[i]+t*2));
            itr--;
            auto itl = cm.lower_bound(X[i]);
            itl--;
            debug(itl->second);
            debug(itr->second);
            result += itr->second - itl->second;
        }
        else if (s[i] == '0') {
            auto itl = cp.lower_bound(max(-INF+1, X[i]-t*2));
            itl--;
            auto itr = cp.lower_bound(X[i]);
            itr--;
            debug(itl->second);
            debug(itr->second);
            result += itr->second - itl->second;
        }
    }
    cout << result / 2 << '\n';

    return 0;
}