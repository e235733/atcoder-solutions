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

    int m, d, cy, cm, cd;
    cin >> m >> d >> cy >> cm >> cd;

    ++cd;
    if (cd > d) {
        ++cm;
        cd -= d;
        if (cm > m) {
            ++cy;
            cm -= m;
        }
    }

    cout << cy << ' ' << cm << ' ' << cd << '\n';

    return 0;
}