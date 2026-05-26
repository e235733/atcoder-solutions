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
    int max_a = *max_element(A.begin(), A.end());
    int max_b = *max_element(B.begin(), B.end());

    cout << max_a + max_b << '\n';

    return 0;
}