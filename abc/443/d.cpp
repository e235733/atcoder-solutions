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

    int t;
    cin >> t;

    rep (_, t) {
        int n;
        cin >> n;

        vector<int> raw(n);
        rep (i, n) {
            cin >> raw[i];
        }
        debug(raw);

        vector<int> lower = raw;
        int p_min = 300001;
        rep (i, n) {
            lower[i] = min(p_min+1, lower[i]);
            p_min = lower[i];
        }
        debug(lower);

        p_min = 300001;
        rep (i, n) {
            lower[n-i-1] = min(p_min+1, lower[n-i-1]);
            p_min = lower[n-i-1];
        }
        debug(lower);

        ll result = 0;
        rep (i, n) {
            result += raw[i] - lower[i];
        }
        cout << result << '\n';
    }

    return 0;
}