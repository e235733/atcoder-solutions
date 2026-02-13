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

    int prev_t = 0;
    int prev_x = 0;
    int prev_y = 0;
    rep (_, n) {
        int t, x, y;
        cin >> t >> x >> y;
        debug(t, x, y);

        // 最短距離を求める
        int min_dist = abs(x - prev_x) + abs(y - prev_y);
        debug(min_dist);

        // 時間内で行けるか調べる
        int dt = t - prev_t;
        debug(dt);
        if (min_dist > dt) {
            cout << "No" << endl;
            return 0;
        }
        
        // 往復で時間を潰せるので、余り時間が偶数か調べる
        int leeway = dt - min_dist;
        debug(leeway);
        if (leeway % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }

        prev_t = t;
        prev_x = x;
        prev_y = y;
    }
    cout << "Yes" << endl;

    return 0;
}