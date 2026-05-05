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

    ll k;
    cin >> k;

    ll result = 0;
    for (ll i=2; i!=k-2; ++i) {
        for (ll j=i+2; j!=k; ++j) {
            ll a = i;
            ll b = j - i;
            ll c = k - j;

            ll num_comb = (a - 1) * (b - 1) * (c - 1);
            if (a >= b && a >= c) {
                result += (b + c) * num_comb;
            }
            else if (b >= a && b >= c) {
                result += (a + c) * num_comb;
            }
            else {
                result += (a + b) * num_comb;
            }
            result %= 998244353;
        }
    }
    cout << result << '\n';

    return 0;
}