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

    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    rep (i, n) cin >> A[i];
    sort(A.begin(), A.end());
    debug(A);

    rep(_, q) {
        int b, k;
        cin >> b >> k;

        int l = -1;
        int r = 200000000;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int li = lower_bound(A.begin(), A.end(), b-mid) - A.begin();
            int ri = upper_bound(A.begin(), A.end(), b+mid) - A.begin();

            if (ri - li >= k) r = mid;
            else l = mid;
        }
        debug(l, r);

        cout << r << '\n';
    }

    return 0;
}