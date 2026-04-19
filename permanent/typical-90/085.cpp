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

    vector<ll> divider;
    for (ll i=1; i*i<=k; ++i) {
        if (k % i != 0) {
            continue;
        }
        divider.push_back(i);
        if (i * i != k) {
            divider.push_back(k / i);
        }
    }
    sort(divider.begin(), divider.end());
    debug(divider);

    int length = divider.size();
    int count = 0;
    rep (i, length) {
        ll d_k = k / divider[i];
        for (int j=i; j!=length; ++j) {
            if (d_k % divider[j] != 0) {
                continue;
            }
            if (d_k / divider[j] >= divider[j]) {
                count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}