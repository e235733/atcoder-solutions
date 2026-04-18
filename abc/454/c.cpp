#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(unordered_map<int, vector<int>> &g, unordered_set<int> &items, vector<bool> &used, int current) {
    for (int next : g[current]) {
        if (!used[next]) {
            debug(next);
            items.insert(next);
            used[next] = true;
            dfs(g, items, used, next);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> g;
    rep (i, m) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }
    debug(g);

    unordered_set<int> items;
    vector<bool> used(n+1);
    items.insert(1);
    used[1] = true;
    dfs(g, items, used, 1);

    cout << items.size() << '\n';

    return 0;
}