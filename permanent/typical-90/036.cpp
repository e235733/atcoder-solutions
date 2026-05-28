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

    vector<ll> dx = {1, -1, -1, 1};
    vector<ll> dy = {1, 1, -1, -1};

    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n), de(4, 0);
    rep (i, n) {
        cin >> x[i] >> y[i];

        rep (j, 4) {
            ll d = x[i] * dx[j] + y[i] * dy[j];
            de[j] = max(de[j], d);
        }
    }
    debug(de);

    rep (_, q) {
        int qi;
        cin >> qi;
        qi--;

        ll result = 0;
        rep (j, 4) {
            ll d = de[j] - x[qi] * dx[j] - y[qi] * dy[j];
            result = max(result, d);
        }
        cout << result << '\n';
    }

    return 0;
}