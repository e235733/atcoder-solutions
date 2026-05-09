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
    int l = 1;
    int r = 2;
    int count = 0;
    rep (_, q) {
        char h;
        int t;
        cin >> h >> t;

        int d_l = l - t;
        if (d_l < 0) {
            d_l += n;
        }
        int d_r = r - t;
        if (d_r < 0) {
            d_r += n;
        }
        debug(d_l, d_r);

        if (h == 'R') {
            if (d_l > d_r) {
                count += d_r;
            }
            else {
                count += n - d_r;
            }
            r -= d_r;
            if (r < 0) {
                r += n;
            }
        }
        else {
            if (d_l > d_r) {
                count += n - d_l;
            }
            else {
                count += d_l;
            }
            l -= d_l;
            if (l < 0) {
                l += n;
            }
        }
    }
    cout << count << '\n';

    return 0;
}