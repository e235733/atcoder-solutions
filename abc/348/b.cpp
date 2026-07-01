#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    vector<int> X(n), Y(n);
    rep (i, n) cin >> X[i] >> Y[i];

    rep (i, n) {
        int md = 0;
        int mj = -1;
        rep (j, n) {
            int d = (X[j] - X[i]) * (X[j] - X[i]) + (Y[j] - Y[i]) * (Y[j] - Y[i]);
            if (d > md) {
                md = d;
                mj = j;
            }
        }

        cout << mj + 1 << '\n';
    }

    return 0;
}