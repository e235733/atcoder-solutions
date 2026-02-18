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

    int n, q;
    cin >> n >> q;

    vector<ll> A(n);
    // i+2 と i+1 の標高差
    vector<ll> diff(n-1);
    // 不便さ
    ll ic = 0;
    rep (i, n) {
        cin >> A[i];
    }
    rep (i, n-1) {
        diff[i] = A[i+1] - A[i];
        ic += abs(diff[i]);
    }
    debug(diff, ic);

    rep (_, q) {
        ll l, r, v;
        cin >> l >> r >> v;
        debug(l, r, v);
        if (l != 1) {
            // 変化後の不便さ
            ll dic = abs(diff[l-2] + v);
            ic += dic - abs(diff[l-2]);

            diff[l-2] += v;
        }
        if (r != n) {
            ll dic = abs(diff[r-1] - v);
            ic += dic - abs(diff[r-1]);

            diff[r-1] -= v;
        }
        debug(diff);

        cout << ic << '\n';
    }

    return 0;
}