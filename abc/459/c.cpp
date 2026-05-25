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

    vector<int> h(n+1, 0), m(q+1, 0);
    int mh = 0;
    rep (_, q) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;

            h[x]++;
            m[h[x]]++;
            if (m[h[x]] == n) {
                mh = h[x];
            }
        }
        else if (t == 2) {
            int y;
            cin >> y;

            if (y+mh > q) {
                cout << 0 << '\n';
            }
            else {
                cout << m[y+mh] << '\n';
            }
        }
        debug(h);
        debug(m);
        debug(mh);
    }

    return 0;
}