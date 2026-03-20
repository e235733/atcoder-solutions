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

    int h, w, q;
    cin >> h >> w >> q;

    rep (_, q) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int r;
            cin >> r;

            cout << r * w << '\n';
            h -= r;
        }
        else {
            int c;
            cin >> c;

            cout << c * h << '\n';
            w -= c;
        }
    }

    return 0;
}