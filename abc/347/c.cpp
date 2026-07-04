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

    unsigned int n, a, b;
    cin >> n >> a >> b;

    set<unsigned int> rem;
    rep (i, n) {
        unsigned int d;
        cin >> d;

        rem.insert(d%(a+b));
        rem.insert(a+b+d%(a+b));
    }
    debug(rem);

    unsigned int p = 0;
    for (unsigned int r : rem) {
        if (r-p >= b) {
            cout << "Yes" << '\n';
            return 0;
        }
        p = r+1;
    }

    cout << "No" << '\n';

    return 0;
}