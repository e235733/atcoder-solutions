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

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> A(n);
    rep (i, n) cin >> A[i];

    rep (i, k) cout << A[i] << ' ';
    cout << x << ' ';
    rep (i, n-k) cout << A[k+i] << ' ';
    cout << '\n';

    return 0;
}