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

    vector<int> Q(n+1), r(n+1);
    rep (i, n) {
        cin >> Q[i+1] >> r[i+1];
    }

    int q;
    cin >> q;
    rep (_, q) {
        int t, d;
        cin >> t >> d;

        debug(d % Q[t]);
        if (d % Q[t] == r[t]) {
            cout << d << '\n';
        }
        else if (d % Q[t] < r[t]) {
            cout << d / Q[t] * Q[t] + r[t] << '\n';
        }
        else {
            cout << Q[t] * (d / Q[t] + 1) + r[t] << '\n';
        }
    }

    return 0;
}