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

    int t;
    cin >> t;
    rep (_, t) {
        ll num_all = 0;
        vector<ll> A(9);
        ll val = 0;
        rep (i, 9) {
            cin >> A[i];
            num_all += A[i];
            if (A[i] != 0) {
                val++;
            }
        }
        if (A[4] * 2 - 1 > num_all) {
            cout << A[4] * 2 - 1 - num_all << '\n';
        }
        else if (val == 2) {
            int val1 = -1; 
            int val2 = -1;
            rep (j, 9) {
                if (A[j] && val1 == -1) {
                    val1 = j + 1;
                }
                else if (A[j]) {
                    val2 = j + 1;
                    break;
                }
            }
            debug(val1, val2);
            if (val1 + val2 == 10) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}