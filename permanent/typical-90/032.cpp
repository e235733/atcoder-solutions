#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<vector<int>> &a, vector<unordered_set<int>> &bad, int n, int &min_time, unordered_set<int> current_left_runners, int prev_runner, int current_block, int prev_time) {
    debug(current_block);
    if (current_block == n) {
        min_time = min(prev_time, min_time);
        debug(min_time);
    }
    else {
        debug(current_left_runners);
        for (int r : current_left_runners) {
            debug(r, bad[prev_runner]);
            if (bad[prev_runner].contains(r)) {
                continue;
            }
            auto next_left_runners = current_left_runners;
            next_left_runners.erase(r);
            int current_time = prev_time + a[r][current_block];
            debug(current_time);
            debug(current_block);
            dfs(a, bad, n, min_time, next_left_runners, r, current_block+1, current_time);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n));
    rep (i, n) {
        rep (j, n) {
            cin >> a[i+1][j];
        }
    }
    debug(a);

    int m;
    cin >> m;
    vector<unordered_set<int>> bad(n + 1);
    rep (_, m) {
        int x, y;
        cin >> x >> y;
        bad[x].insert(y);
        bad[y].insert(x);
    }
    debug(bad);
    
    unordered_set<int> left_runners;
    rep (i, n) {
        left_runners.insert(i+1);
    }
    debug(left_runners);

    int min_time = 1000000000;
    dfs(a, bad, n, min_time, left_runners, 0, 0, 0);

    if (min_time == 1000000000) {
        cout << -1 << '\n';
    }
    else {
        cout << min_time << '\n';
    }

    return 0;
}