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

    ll sa = 0;
    ll mh = 0;
    rep (i, n) {
        ll a, b;
        cin >> a >> b;
        sa += a;
        mh = max(mh, b - a);
    }

    cout << sa + mh << '\n';

    return 0;
}