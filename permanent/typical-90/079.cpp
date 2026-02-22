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

    vector<vector<ll>> diff(h, vector<ll>(w));
    rep (i, h) {
        rep (j, w) {
            cin >> diff[i][j];
        }
    }
    rep (i, h) {
        rep (j, w) {
            ll b;
            cin >> b;
            diff[i][j] -= b;
        }
    }
    debug(diff);

    ll sum = 0;
    // 左上から走査していく
    queue<pair<int, int>> p;
    p.push({0, 0});
    while (!p.empty()) {
        debug(p);
        queue<pair<int, int>> next_p;
        while (!p.empty()) {
            int i = p.front().first;
            int j = p.front().second;
            ll d = diff[i][j];
            debug(i, j, d);
            sum += abs(d);
            diff[i][j] -= d;
            diff[i+1][j] -= d;
            diff[i][j+1] -= d;
            diff[i+1][j+1] -= d;
            debug(diff);

            if (j + 2 < w) {
                next_p.push({i, j+1});
            }

            p.pop();

            if (p.empty() && i + 2 < h) {
                next_p.push({i+1, j});
            }
        }
        p = next_p;
    }

    // diff の縁を調べる
    rep (i, h) {
        if (diff[i][w-1] != 0) {
            cout << "No" << '\n';
            return 0;
        }
    }
    rep (j, w) {
        if (diff[h-1][j] != 0) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes\n" << sum << '\n';

    return 0;
}