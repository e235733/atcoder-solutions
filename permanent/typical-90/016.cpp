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

    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    debug(n, a, b, c);

    ll min_count = 1000000000;
    rep (i, 10000) {
        //debug(i);
        if (a * i > n) {
            break;
        }
        rep (j, 10000) {
            ll v = a * i + b * j;
            //debug(j, v);
            if (v > n) {
                break;
            }
            ll remain = n - v;
            if (remain % c == 0) {
                ll k = remain / c;
                ll count = i + j + k;
                debug(i, j, k, count);
                min_count = min(count, min_count);
            }
        }
    }
    cout << min_count << '\n';

    return 0;
}