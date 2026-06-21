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

    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    rep (i, n) cin >> A[i];
    rep (i, m) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int j = 0;
    ll result = 0;
    rep (i, n) {
        if (j == m) break;
        if (B[j] <= A[i]) {
            result += A[i];
            j++;
        }
    }

    if (j == m) cout << result << '\n';
    else cout << -1 << '\n';

    return 0;
}