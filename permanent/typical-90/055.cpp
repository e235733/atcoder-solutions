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

    int n, p, q;
    cin >> n >> p >> q;
    debug(n, p, q);

    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    debug(A);

    int count = 0;
    // すべての組み合わせについて考える
    for (int i=0; i!=n-4; ++i) {
        for (int j=i+1; j!=n-3; ++j) {
            for (int k=j+1; k!=n-2; ++k) {
                for (int l=k+1; l!=n-1; ++l) {
                    for (int m=l+1; m!=n; ++m) {
                        ll result = 1LL * A[i] * A[j] % p * A[k] % p * A[l] % p * A[m] % p;
                        if (result == q) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}