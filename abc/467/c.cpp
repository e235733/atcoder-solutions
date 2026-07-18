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

    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(n-1);
    rep (i, n) cin >> A[i];
    rep (i, n-1) cin >> B[i];

    int j = -1;
    rep (i, n-1) {
        if ((A[i] + A[i+1]) % m != B[i]) {
            j = i;
            break;
        }
    }

    if (j == -1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> C = A;
    if (C[0] == 0) C[0] = 1;
    else if (C[0] == 1) C[0] = 0;
    int r1 = 1;
    for (int i=0; i!=n-1; ++i) {
        if ((C[i] + C[i+1]) % m != B[i]) {
            ++r1;
            ++C[i+1];
        }
    }
    debug(C);
    
    int r2 = 0;
    for (int i=0; i!=n-1; ++i) {
        if ((A[i] + A[i+1]) % m != B[i]) {
            ++r2;
            ++A[i+1];
        }
    }
    debug(A);

    cout << min(r1, r2) << '\n';

    return 0;
}