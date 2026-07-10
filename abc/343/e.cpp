#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    int a1 = 0, b1 = 0, c1 = 0;
    rep (a2, 8) rep (b2, 8) rep (c2, 8) {
        for (int a3 = -7; a3 <= 7; ++a3)
        for (int b3 = -7; b3 <= 7; ++b3)
        for (int c3 = -7; c3 <= 7; ++c3) {

            int p1 = 1029, p2 = 0, p3 = 0;

            int pa12 = max(0, min(a1+7-a2, a2+7-a1));
            int pb12 = max(0, min(b1+7-b2, b2+7-b1));
            int pc12 = max(0, min(c1+7-c2, c2+7-c1));
            int p12 = pa12 * pb12 * pc12;

            int pa23 = max(0, min(a2+7-a3, a3+7-a2));
            int pb23 = max(0, min(b2+7-b3, b3+7-b2));
            int pc23 = max(0, min(c2+7-c3, c3+7-c2));
            int p23 = pa23 * pb23 * pc23;

            int pa31 = max(0, min(a3+7-a1, a1+7-a3));
            int pb31 = max(0, min(b3+7-b1, b1+7-b3));
            int pc31 = max(0, min(c3+7-c1, c1+7-c3));
            int p31 = pa31 * pb31 * pc31;

            p1 -= p12 * 2 + p23 * 2 + p31 * 2;
            p2 = p12 + p23 + p31;

            int ac[28] = {}, bc[28] = {}, cc[28] = {};
            for (int i=a1; i!=a1+7; ++i) ++ac[i+7];
            for (int i=b1; i!=b1+7; ++i) ++bc[i+7];
            for (int i=c1; i!=c1+7; ++i) ++cc[i+7];

            for (int i=a2; i!=a2+7; ++i) ++ac[i+7];
            for (int i=b2; i!=b2+7; ++i) ++bc[i+7];
            for (int i=c2; i!=c2+7; ++i) ++cc[i+7];

            for (int i=a3; i!=a3+7; ++i) ++ac[i+7];
            for (int i=b3; i!=b3+7; ++i) ++bc[i+7];
            for (int i=c3; i!=c3+7; ++i) ++cc[i+7];

            int ca3 = 0, cb3 = 0, cc3 = 0;
            rep (i, 28) if (ac[i] == 3) ++ca3;
            rep (i, 28) if (bc[i] == 3) ++cb3;
            rep (i, 28) if (cc[i] == 3) ++cc3;

            int p123 = ca3 * cb3 * cc3;
            p1 += p123 * 3;
            p2 -= p123 * 3;
            p3 = p123;

            if (v1 == p1 && v2 == p2 && v3 == p3) {
                cout << "Yes" << '\n';
                cout << a1 << ' ' << b1 << ' ' << c1 << ' '
                     << a2 << ' ' << b2 << ' ' << c2 << ' '
                     << a3 << ' ' << b3 << ' ' << c3 << '\n';
                return 0;
            }
        }
    }

    cout << "No" << '\n';

    return 0;
}