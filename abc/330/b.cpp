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

    int n, l, r;
    cin >> n >> l >> r;

    rep (i, n) {
        int a;
        cin >> a;

        if (a >= l && a <= r) {
            cout << a << ' ';
        }
        else if (a < l) {
            cout << l << ' ';
        }
        else if (a > r) {
            cout << r << ' ';
        }
    }
    cout << '\n';

    return 0;
}