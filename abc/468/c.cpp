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

    int n;
    cin >> n;
    vector<int> P(n), Q(n);
    rep (i, n) cin >> P[i];
    rep (i, n) cin >> Q[i];

    bool ok = false;
    int ans = 0;
    do {
        if (P == Q) {
            ok = true;
            break;
        }
        ++ans;
    } while (next_permutation(P.begin(), P.end()));

    if (!ok) {
        cout << 0 << '\n';
        return 0;
    }

    cout << max(0, ans-1) << '\n';

    return 0;
}