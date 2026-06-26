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
    vector<int> h(n);
    rep (i, n) cin >> h[i];

    int oh = h[0];

    rep (i, n-1) {
        if (h[i+1] > oh) {
            cout << i+2 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}