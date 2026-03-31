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

    int n, m;
    cin >> n >> m;

    vector<bool> is_left(m+1, true);
    rep (_, n) {
        int l;
        cin >> l;

        vector<int> X(l);
        rep (i, l) {
            cin >> X[i];
        }
        
        bool no_drink = true;
        for (int x : X) {
            if (is_left[x]) {
                cout << x << '\n';
                is_left[x] = false;
                no_drink = false;
                break;
            }
        }
        if (no_drink) {
            cout << 0 << '\n';
        }
    }

    return 0;
}