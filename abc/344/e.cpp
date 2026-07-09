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
    vector<int> A(n+2);
    A[0] = -1;
    A[n+1] = 1<<30;
    rep (i, n) cin >> A[i+1];

    map<int, int> L, R;
    rep (i, n+1) {
        L[A[i+1]] = A[i];
        R[A[i]] = A[i+1];
    }
    debug(L);
    debug(R);

    int q;
    cin >> q;
    rep (_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            int rx = R[x];
            L[y] = x;
            L[rx] = y;
            R[x] = y;
            R[y] = rx;
        }
        else if (t == 2) {
            int x;
            cin >> x;
            int rx = R[x];
            int lx = L[x];

            L[rx] = lx;
            R[lx] = rx;
        }
    }

    int a = -1;
    while (R.contains(a)) {
        if (R[a] != 1<<30) cout << R[a] << ' ';
        a = R[a];
    }
    cout << '\n';

    return 0;
}