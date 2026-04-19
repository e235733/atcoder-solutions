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

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> A(n);
    rep (i, n) {
        int a;
        cin >> a;
        A[i] = a % k;
    }
    debug(A);

    sort(A.begin(), A.end());
    if (A.front() == A.back()) {
        cout << 0 << '\n';
        return 0;
    }

    int max_dist = A.front() + k - A.back();
    rep (i, n-1) {
        max_dist = max(max_dist, A[i+1] - A[i]);
    }
    cout << k - max_dist << '\n';

    return 0;
}