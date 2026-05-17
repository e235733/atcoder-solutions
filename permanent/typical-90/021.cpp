#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<vector<int>>& g, vector<bool>& used, vector<int>& ord, int c) {
    used[c] = true;

    for (int nc : g[c]) {
        if (used[nc]) {
            continue;
        }

        dfs(g, used, ord, nc);
    }

    ord.push_back(c);
}

void dfs2(vector<vector<int>>& h, vector<bool>& used, int& count, int c) {
    used[c] = true;
    count++;
    debug(c, count);

    for (int nc : h[c]) {
        if (used[nc]) {
            continue;
        }

        dfs2(h, used, count, nc);
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

    vector<vector<int>> g(n+1), h(n+1);
    rep (_, m) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        h[b].push_back(a);
    }

    vector<bool> used(n+1, false);
    vector<int> ord;
    ord.reserve(n);
    rep (i, n) {
        if (used[i+1]) {
            continue;
        }

        dfs(g, used, ord, i+1);
    }

    reverse(ord.begin(), ord.end());
    debug(ord);
    used = vector<bool>(n+1, false);
    debug(h);

    ll result = 0;
    rep (i, n) {
        debug(ord[i]);
        if (used[ord[i]]) {
            continue;
        }
        int count = 0;
        dfs2(h, used, count, ord[i]);
        debug(count);

        result += 1LL * count * (count - 1) / 2;
    }

    cout << result << '\n';

    return 0;
}