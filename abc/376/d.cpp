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

    unordered_map<int, vector<int>> g;
    unordered_map<int, unordered_map<int, bool>> used;
    rep (_, m) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        used[a][b] = false;
    }

    if (!g.contains(1)) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> currents = g[1];
    for (int c : currents) {
        used[1][c] = true;
    }
    int count = 1;
    while (currents.size()) {
        count++;
        vector<int> nexts;
        for (int c : currents) {
            for (int next : g[c]) {
                if (used[c][next]) {
                    continue;
                }

                if (next == 1) {
                    cout << count << '\n';
                    return 0;
                }

                used[c][next] = true;
                nexts.push_back(next);
            }
        }
        currents = nexts;
    }

    cout << -1 << '\n';

    return 0;
}