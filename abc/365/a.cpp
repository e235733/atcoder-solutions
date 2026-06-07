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

    int y;
    cin >> y;

    if (y % 4 != 0) {
        cout << 365 << '\n';
    }
    else {
        if (y % 100 != 0) {
            cout << 366 << '\n';
        }
        else {
            if (y % 400 != 0) {
                cout << 365 << '\n';
            }
            else {
                cout << 366 << '\n';
            }
        }
    }

    return 0;
}