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

    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    ll ans = 1;

    ll ok = 1;
    ll ng = 1 << 30;
    while (ok + 1 < ng) {
        ll mid = (ok + ng) / 2;
        //debug(mid);
        if (mid * mid > n) ng = mid;
        else ok = mid;
    }
    debug(ok);
    ans += ok - 1;

    set<ll> ignore;
    for (ll i=3; i!=61; ++i) {
        debug(i);
        ll j = 2;
        ll jn = 0;
        while (true) {
            ll a = 1;
            bool over = false;
            rep (_, i) {
                if (a > n / j) {
                    over = true;
                    break;
                }
                a *= j;
            }
            if (a > n || over) break;
            //debug(j);

            if (ignore.contains(a)) {
                ++j;
                continue;
            }

            ll aok = 2;
            ll ang = 1 << 30;
            while (aok + 1 < ang) {
                ll mid = (aok + ang) / 2;
                //debug(mid);
                if (mid * mid > a) ang = mid;
                else aok = mid;
            }
            //debug(aok);
            if (aok * aok == a) {
                ++j;
                continue;
            }

            ++jn;
            ++j;
            ignore.insert(a);
        }
        debug(jn);
        ans += jn;
    }

    cout << ans << '\n';

    return 0;
}