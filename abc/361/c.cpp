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
    rep (i, n) cin >> A[i];

    sort(A.begin(), A.end());
    int d = n - k - 1;

    int ans = 1 << 30;
    rep (i, n-d) ans = min(A[i+d] - A[i], ans);

    cout << ans << '\n';

    return 0;
}