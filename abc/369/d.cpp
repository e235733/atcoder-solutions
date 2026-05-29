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

    vector<ll> o(n), e(n);
    cin >> o[0];
    e[0] = 0;

    rep (i, n-1) {
        ll a;
        cin >> a;
        o[i+1] = max(o[i], e[i] + a);
        e[i+1] = max(o[i] + a * 2, e[i]);
    }

    cout << max(o[n-1], e[n-1]) << '\n';

    return 0;
}