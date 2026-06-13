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
    vector<pair<int, int>> xy(n);
    rep (i, n) {
        int x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }
    sort(xy.begin(), xy.end());

    int max_y = 1000000000;
    int count = 0;
    rep (i, n) {
        if (xy[i].second < max_y) {
            count++;
        }
        max_y = min(xy[i].second, max_y);
    }

    cout << count << '\n';

    return 0;
}