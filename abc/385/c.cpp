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

    vector<int> h(n);
    rep (i, n) {
        cin >> h[i];
    }

    int max_combo = 1;
    for (int i=1; i!=n; ++i) {
        debug(i);
        // i 個おきに調べる、開始位置は j
        rep (j, i) {
            debug(i, j);
            int pos = j;
            int num_combo = 0;
            int prev = -1;
            while (pos < n) {
                debug(i, j, pos);
                if (h[pos] == prev) {
                    num_combo++;
                }
                else {
                    max_combo = max(max_combo, num_combo);
                    num_combo = 1;
                }
                debug(prev, h[pos], num_combo);
                prev = h[pos];
                pos += i;
            }
            max_combo = max(max_combo, num_combo);
            debug(max_combo);
        }
    }
    cout << max_combo << '\n';

    return 0;
}