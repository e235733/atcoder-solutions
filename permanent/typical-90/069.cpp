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

    ll divider = 1;
    rep (_, 9) {
        divider *= 10;
    }
    divider += 7;
    debug(n, k, divider);

    if (n == 1) {
        cout << k << '\n';
        return 0;
    }
    
    if (n == 2) {
        if (k < 2) {
            cout << 0 << '\n';
            return 0;
        }
        ll result = k * (k - 1) % divider;
        cout << result << '\n';
        return 0;
    }

    if (k < 3) {
        cout << 0 << '\n';
        return 0;
    }
    // 繰り返し二乗法
    vector<ll> rem;
    rem.push_back(k - 2);
    // k - 2 を掛ける回数
    ll m = 2;
    while (m <= n - 2) {
        ll next = rem.back() * rem.back() % divider;
        rem.push_back(next);
        m *= 2;
    }
    debug(rem);

    ll result = k * (k - 1) % divider;
    ll l = n - 2;
    int digit = 0;
    while (l != 0) {
        if (l % 2 == 1) {
            result *= rem[digit];
            result %= divider;
        }
        debug(l, digit, result);
        l /= 2;
        digit++;
    }

    cout << result << '\n';

    return 0;
}