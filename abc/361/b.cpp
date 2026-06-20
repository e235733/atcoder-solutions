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

    int ax1, ay1, az1, ax2, ay2, az2, bx1, by1, bz1, bx2, by2, bz2;
    cin >> ax1 >> ay1 >> az1 >> ax2 >> ay2 >> az2 >> bx1 >> by1 >> bz1 >> bx2 >> by2 >> bz2;

    if (bx2 <= ax1 || bx1 >= ax2 || by2 <= ay1 || by1 >= ay2 || bz2 <= az1 || bz1 >= az2) cout << "No" << '\n';
    else cout << "Yes" << '\n';

    return 0;
}