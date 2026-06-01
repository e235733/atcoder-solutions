#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(int n, int k, vector<int> &r, vector<vector<int>> &result, int i, vector<int> &c, int cs) {
    debug(i, c, cs);
    if (i == n) {
        if (cs % k == 0) {
            result.push_back(c);
        }
        return;
    }

    int ri = r[i];
    for (int j=1; j!=ri+1; ++j) {
        c[i] = j;
        dfs (n, k, r, result, i+1, c, cs+j);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    rep (i, n) {
        cin >> r[i];
    }

    vector<vector<int>> result;
    vector<int> c(n);
    dfs (n, k, r, result, 0, c, 0);

    for (vector<int> res : result) {
        rep(i, n) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}