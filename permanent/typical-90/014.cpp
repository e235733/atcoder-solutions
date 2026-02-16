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

    vector<int> A(n), B(n);
    rep (i, n) {
        cin >> A[i];
    }
    rep (i, n) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    debug(A);
    debug(B);

    ll result = 0;
    rep (i, n) {
        result += abs(A[i] - B[i]);
    }
    cout << result << '\n';

    return 0;
}