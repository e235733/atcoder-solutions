#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(map<int, int>& count, set<int>& pair, int prev, int current, vector<int>& A, vector<vector<int>>& g, vector<bool>& result) {
    result[current] = pair.size();

    for (int next : g[current]) {
        if (next == prev) {
            continue;
        }
        count[A[next]]++;
        if (count[A[next]] == 2) {
            pair.insert(A[next]);
        }
        dfs(count, pair, current, next, A, g, result);
        count[A[next]]--;
        if (count[A[next]] == 1) {
            pair.erase(A[next]);
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

    vector<int> A(n+1);
    rep (i, n) {
        cin >> A[i+1];
    }
    vector<vector<int>> g(n+1);
    rep (i, n-1) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    debug(g);

    map<int, int> count;
    count[A[1]]++;
    set<int> pair;
    vector<bool> result(n+1);
    result[1] = false;
    dfs(count, pair, 0, 1, A, g, result);

    rep (i, n) {
        if (result[i+1]) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }

    return 0;
}