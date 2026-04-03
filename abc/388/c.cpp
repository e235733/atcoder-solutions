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

    vector<ll> A(n);
    rep (i, n) {
        cin >> A[i];
    }

    ll count = 0;
    rep (i, n-1) {
        debug(i, A[i]);
        if (A[i] * 2 > A[n-1]) {
            break;
        }

        int ng = i;
        int ok = n;
        while (ng + 1 < ok) {
            int mid = (ng + ok) / 2;
            if (A[i] * 2 > A[mid]) {
                ng = mid;
            }
            else {
                ok = mid;
            }
            debug(ng, ok);
        }
        count += n - ok;
    }
    cout << count << '\n';

    return 0;
}