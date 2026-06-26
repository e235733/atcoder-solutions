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

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    rep (i, n) cin >> A[i];

    int lk = k;
    int count = 0;
    rep (i, n) {
        if (lk >= A[i]) {
            lk -= A[i];
        }
        else {
            count++;
            lk = k - A[i];
        }
    }

    cout << count + 1 << '\n';

    return 0;
}