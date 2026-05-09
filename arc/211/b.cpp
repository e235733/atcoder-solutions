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

    int x, y, z;
    cin >> x >> y >> z;

    if (x == y) {
        cout << x << ' ';
        rep (_, x) {
            cout << 0 << ' ';
        }
        cout << '\n';

        rep (_, 2) {
            cout << z << ' ';
            rep (i, z) {
                cout << 0 << ' ';
            }
            cout << '\n';
        }
    }
    else {
        cout << x + y << ' ';
        rep (_, x) {
            cout << 1 << ' ';
        }
        rep (_, y) {
            cout << 0 << ' ';
        }
        cout << '\n';

        cout << z << ' ';
        rep (_, z) {
            cout << 1 << ' ';
        }
        cout << '\n';

        cout << y + z << ' ';
        rep (_, y) {
            cout << 0 << ' ';
        }
        rep (_, z) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}