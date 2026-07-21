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

    char s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;

    int ds = abs((s1-'A') - (s2-'A'));
    int es = min(ds, 5-ds);
    debug(es);

    int dt = abs((t1-'A') - (t2-'A'));
    int et = min(dt, 5-dt);
    debug(et);

    if (es == et) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}