#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int n, m;
vector<int> A(100), X(100, 0);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    rep (i, m) cin >> A[i];
    
    rep (_, n) rep (i, m) {
        int m;
        cin >> m;
        X[i] += m;
    }

    rep (i, m) {
        if (A[i] > X[i]) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}