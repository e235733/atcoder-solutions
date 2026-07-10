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

    ll n;
    cin >> n;

    ll l = 0;
    ll r = 1 << 20;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (mid * mid * mid <= n) l = mid;
        else r = mid;
    }
    debug(l);

    ll ans = -1;

    for (ll i=1; i!=l+1; ++i) {
        vector<int> M;
        ll la = i * i * i;
        while (la != 0) {
            M.push_back(la % 10);
            la /= 10;   
        }
        debug(M);

        bool ok = true;
        int len = M.size();
        rep (j, len/2) {
            if (M[j] != M[len-j-1]) {
                ok = false;
                break;
            }
        }

        if (ok) ans = i * i * i;
    }
    cout << ans << '\n';

    return 0;
}