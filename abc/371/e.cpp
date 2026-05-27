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

    map<int, vector<int>> pos;
    rep (i, n) {
        int a;
        cin >> a;

        pos[a].push_back(i);
    }
    debug(pos);

    ll inc = 0;
    for (auto [m, p] : pos) {
        int pi = 0;
        for (int ci : p) {
            inc += 1LL * (ci - pi + 1) * (ci - pi) / 2;
            pi = ci + 1;
        }
        inc += 1LL * (n - pi + 1) * (n - pi) / 2;
    }
    debug(inc);

    cout << 1LL * (n + 1) * n / 2 * pos.size() - inc << '\n';

    return 0;
}