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

    int sa = 0;
    int sb = 0;
    rep (_, 9) {
        int a;
        cin >> a;
        sa += a;
    }
    rep (_, 8) {
        int b;
        cin >> b;
        sb += b; 
    }

    cout << sa - sb + 1 << '\n';

    return 0;
}