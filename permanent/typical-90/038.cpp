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

    ll a, b;
    cin >> a >> b;
    debug(a, b);

    ll c = a;
    ll d = b;
    while (c != 0 && d != 0) {
        if (c > d) {
            c %= d;
        }
        else {
            d %= c;
        }
    }
    ll gcd = c + d;
    debug(gcd);

    __int128_t lcm = (__int128_t)a * b / gcd;
    ll top_lim = 1;
    debug(top_lim);
    rep (_, 18) {
        top_lim *= 10;
    }

    if (lcm > top_lim) {
        cout << "Large" << '\n';
    }
    else {
        cout << (ll)lcm << '\n';
    }

    return 0;
}