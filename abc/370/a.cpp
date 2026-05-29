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

    int l, r;
    cin >> l >> r;

    if (l == 0) {
        if (r == 0) {
            cout << "Invalid" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }
    else {
        if (r == 0) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "Invalid" << '\n';
        }
    }

    return 0;
}