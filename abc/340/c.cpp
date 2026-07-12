#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
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

    ull n;
    cin >> n;

    ull ans = 0;
    ull um = n, dm = n, uc = 0, dc = 1;
    while (um != 1 || dm != 1) {
        debug(um, dm, uc, dc);
        ull nuc = 0, ndc = 0;

        if (um != 1) {
            ans += um * uc;
            if (um % 2 == 0) {
                nuc += uc * 2;
                um = um / 2;
            }
            else {
                nuc += uc;
                ndc += uc;
                um = um / 2 + 1;
            }
        }
        debug(nuc, ndc);

        if (dm != 1) {
            ans += dm * dc;
            if (dm % 2 == 0) {
                ndc += dc * 2;
            }
            else {
                nuc += dc;
                ndc += dc;
            }
            dm = dm / 2;
        }
        debug(nuc, ndc);
        uc = nuc, dc = ndc;
        debug(ans);
    }

    cout << ans << '\n';

    return 0;
}