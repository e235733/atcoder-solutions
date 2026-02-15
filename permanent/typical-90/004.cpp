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

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    // 各行・列の和
    vector<int> sum_row(h, 0);
    vector<int> sum_col(w, 0);

    rep (i, h) {
        rep (j, w) {
            int a_i;
            cin >> a_i;
            a[i][j] = a_i;
            sum_row[i] += a_i;
            sum_col[j] += a_i;
        }
    }
    debug(a);
    debug(sum_row);
    debug(sum_col);

    rep (i, h) {
        rep (j, w) {
            int result = sum_row[i] + sum_col[j] - a[i][j];
            cout << result << ' ';
        }
        cout << endl;
    }

    return 0;
}