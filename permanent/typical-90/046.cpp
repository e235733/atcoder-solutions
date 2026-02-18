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
    vector<int> A(n), B(n), C(n);
    rep (i, n) {
        cin >> A[i];
    }
    rep (i, n) {
        cin >> B[i];
    }
    rep (i, n) {
        cin >> C[i];
    }

    // 46 で割ったあまりとその数
    vector<int> rem_a(46, 0), rem_b(46, 0), rem_c(46, 0);
    rep (i, n) {
        int rem = A[i] % 46;
        rem_a[rem]++;
    }
    rep (i, n) {
        int rem = B[i] % 46;
        rem_b[rem]++;
    }
    rep (i, n) {
        int rem = C[i] % 46;
        rem_c[rem]++;
    }
    debug(rem_a);
    debug(rem_b);
    debug(rem_c);

    // 46 で割り切れる組み合わせの数
    ll count = 0;
    rep (i, 46) {
        rep (j, 46) {
            rep (k, 46) {
                int rem = (i + j + k) % 46;
                //debug(i, j, k, rem);
                if (rem == 0) {
                    count += 1LL * rem_a[i] * rem_b[j] * rem_c[k];
                }
            }
        }
    }
    cout << count << '\n';

    return 0;
}