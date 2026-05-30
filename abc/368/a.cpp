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

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }

    rep (i, k) {
        cout << A[n-k+i] << ' ';
    }
    rep (i, n-k) {
        cout << A[i] << ' ';
    }
    cout << '\n';

    return 0;
}