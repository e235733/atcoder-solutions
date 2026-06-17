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

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int abx = xb - xa;
    int aby = yb - ya;
    debug(abx, aby);
    int acx = xc - xa;
    int acy = yc - ya;
    debug(acx, acy);
    int bcx = xc - xb;
    int bcy = yc - yb;
    debug(bcx, bcy);
    if (abx*acx+aby*acy && abx*bcx+aby*bcy && acx*bcx+acy*bcy) cout << "No" << '\n';
    else cout << "Yes" << '\n';

    return 0;
}