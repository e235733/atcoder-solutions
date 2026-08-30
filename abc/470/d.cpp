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

    int n, q;
    cin >> n >> q;
    vector<int> A(n+1), B(n+1);
    rep (i, n) {
        cin >> A[i+1];
        B[A[i+1]] = i + 1;
    }

    bool aa = true;
    rep (_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (aa) {
                swap(A[x], A[y]);
                swap(B[A[x]], B[A[y]]);
            }
            else {
                swap(B[x], B[y]);
                swap(A[B[x]], A[B[y]]);
            }
        }
        else if (t == 2) {
            aa = !aa;
        }
    }

    if (aa) {
        rep (i, n) {
            cout << A[i+1] << ' ';
        }
    }
    else {
        rep (i, n) {
            cout << B[i+1] << ' ';
        }
    }
    cout << '\n';

    return 0;
}