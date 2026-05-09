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

    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> vec(n);
    rep (i, n) {
        ll l;
        cin >> l;

        vec[i].reserve(l);
        rep (j, l) {
            ll a;
            cin >> a;
            vec[i].push_back(a);
        }
    }
    debug(vec);

    vector<ll> length(n);
    vector<ll> C(n);
    rep (i, n) {
        cin >> C[i];
        length[i] = vec[i].size() * C[i];
    }
    debug(length);

    int i = 0;
    while (k > length[i]) {
        k -= length[i];
        i++;
    }
    debug(i);
    k--;
    k %= vec[i].size();
    cout << vec[i][k] << '\n';

    return 0;
}