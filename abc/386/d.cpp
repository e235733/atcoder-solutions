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

    // 各行について、黒の右端と白の左端
    map<int, pair<int, int>> range;

    rep (_, m) {
        int x, y;
        char c;
        cin >> x >> y >> c;

        if (c == 'B') {
            if (range.contains(x)) {
                range[x].first = max(range[x].first, y);
            }
            else {
                range[x] = {y, n};
            }
        }
        else {
            if (range.contains(x)) {
                range[x].second = min(range[x].second, y - 1);
            }
            else {
                range[x] = {0, y - 1};
            }
        }
        debug(range[x]);

        if (range[x].first > range[x].second) {
            cout << "No" << '\n';
            return 0;
        }
    }
    debug(range);

    int left = 0;
    auto it = range.rbegin();
    while (it != range.rend()) {
        pair<int, int> p = it->second;
        debug(p.second, left);
        if (p.second < left) {
            cout << "No" << '\n';
            return 0;
        }
        debug(p.first, left);
        left = max(left, p.first);
        it++;
    }

    cout << "Yes" << '\n';

    return 0;
}