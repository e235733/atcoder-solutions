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

    vector<ll> X(n), Y(n);

    rep (i, n) {
        ll x, y;
        cin >> x >> y;

        X[i] = x;
        Y[i] = y;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll plant_x = X[(n-1)/2];
    ll plant_y = Y[(n-1)/2];
    debug(plant_x, plant_y);

    ll result = 0;
    rep (i, n) {
        result += abs(X[i] - plant_x);
        result += abs(Y[i] - plant_y);
    }

    cout << result << '\n';

    return 0;
}