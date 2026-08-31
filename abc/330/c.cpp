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

    ll d;
    cin >> d;

    ll ans = 1LL<<40;
    for (ll x=0; x*x*2<=d; ++x) {
        //debug(x);
        ll rok = 1<<30;
        ll rng = -1;
        while (rng + 1 < rok) {
            ll mid = (rng + rok) / 2;
            if (x * x + mid * mid >= d) {
                rok = mid;
            }
            else {
                rng = mid;
            }
        }
        //debug(rok);
        ll lok = 0;
        ll lng = 1<<30;
        while (lok + 1 < lng) {
            ll mid = (lng + lok) / 2;
            if (x * x + mid * mid <= d) {
                lok = mid;
            }
            else {
                lng = mid;
            }
        }
        //debug(lok);

        ll p1 = x * x + rok * rok - d;
        ll p2 = d - x * x - lok * lok;
        ans = min(ans, min(p1, p2));
    }

    cout << ans << '\n';

    return 0;
}