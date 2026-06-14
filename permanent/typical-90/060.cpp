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

    int INF = 1 << 30;

    int n;
    cin >> n;
    vector<int> A(n);
    rep (i, n) cin >> A[i];

    vector<int> B(n);
    vector<int> dpl(n, INF);
    rep (i, n) {
        int j = lower_bound(dpl.begin(), dpl.end(), A[i]) - dpl.begin();
        B[i] = j;
        dpl[j] = A[i];
        debug(dpl);
    }
    vector<int> dpr(n, INF);
    rep (i, n) {
        int j = lower_bound(dpr.begin(), dpr.end(), A[n-i-1]) - dpr.begin();
        B[n-i-1] += j;
        dpr[j] = A[n-i-1];
        debug(dpr);
    }
    debug(B);

    cout << *max_element(B.begin(), B.end()) + 1 << '\n';

    return 0;
}