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

    int prev_t, prev_v;
    cin >> prev_t >> prev_v;

    rep (_, n-1) {
        int t, v;
        cin >> t >> v;

        prev_v = max(0, prev_v - t + prev_t);
        prev_v += v;

        prev_t = t;
        debug(prev_v);
    }
    cout << prev_v << '\n';

    return 0;
}