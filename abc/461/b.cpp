#include <bits/stdc++.h>
using namespace std;
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

    vector<int> A(n+1), B(n+1);
    rep (i, n) {
        cin >> A[i+1];
    }
    rep (i, n) {
        cin >> B[i+1];
    }

    bool ok = true;
    rep (i, n) {
        debug(B[A[i+1]]);
        if (B[A[i+1]] != i+1) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }


    return 0;
}