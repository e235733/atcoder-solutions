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

    int n;
    cin >> n;
    vector<ll> H(n);
    rep (i, n) {
        cin >> H[i];
    }

    vector<vector<ll>> b = {{0, 1, 2, 3, 3}, {0, 1, 2, 2, 2}, {0, 1, 1, 1, 2}};
    ll count = 0;
    rep (i, n) {
        ll m3 = count % 3;
        ll m5 = H[i] % 5;
        ll q5 = H[i] / 5;

        count += q5 * 3 + b[m3][m5];
    }

    cout << count << '\n';

    return 0;
}