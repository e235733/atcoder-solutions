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

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m), sum_b(m+1);
    rep (i, n) {
        cin >> a[i];
    }
    rep (i, m) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    rep (i, m) {
        sum_b[i+1] = sum_b[i] + b[i];
    }
    debug(b);
    
    ll result = 0;
    rep (i, n) {
        debug(a[i]);
        // 2分探索で a 以上で最小の b の位置を求める
        int l = -1;
        int r = m;
        while (r > l + 1) {
            int mid = (l + r) / 2;
            if (b[mid] >= a[i]) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        debug(r, b[l], b[r]);

        ll u = a[i] * r - sum_b[r];
        ll v = sum_b[m] - sum_b[r] - a[i] * (m - r);
        result += u + v;
        result %= 998244353;
    }
    cout << result << '\n';

    return 0;
}