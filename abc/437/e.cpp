#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs (auto& g, vector<int> currents) {
    map<int, vector<int>> next_groups;
    for (int c : currents) {
        for (auto& p : g[c]) {
            for (int next : p.second) { 
                next_groups[p.first].push_back(next);
            }
        }
    }

    for (auto& p : next_groups) {
        sort(p.second.begin(), p.second.end()); 
        
        for (int next : p.second) { 
            cout << next << ' ';
        }
        dfs (g, p.second);
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

    // idx = 親
    // {{子_v, {p_idx}}}
    vector<map<int, vector<int>>> g(n+1);
    rep (i, n) {
        int x, y;
        cin >> x >> y;

        g[x][y].push_back(i+1);
    }
    rep (i, n+1) {
        for (auto& p : g[i]) {
            sort(p.second.begin(), p.second.end());
        }
    }
    debug(g);

    dfs(g, {0});
    cout << '\n';

    return 0;
}