#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(unordered_map<int, vector<int>> &to, int o, int prev, vector<int> &result) {
    if (to.contains(prev)) {
        vector<int> current = to[prev];
        debug(current);
        for (int c : current) {
            debug(c);
            result[c-1] = o;
            dfs(to, o, c, result);
        }
        debug(result);
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

    // 逆向きの有向グラフを作成
    unordered_map<int, vector<int>> to;
    // すでに収束位置にいる a 
    unordered_set<int> origin;
    rep (i, n) {
        int a;
        cin >> a;

        if (a == i + 1) {
            origin.insert(a);
        } 
        else if (to.contains(a)){
            to[a].push_back(i + 1);
        }
        else {
            to[a] = {i + 1};
        }
    }
    debug(to);
    debug(origin);

    vector<int> result(n);
    for (int o : origin) {
        debug(o);
        result[o-1] = o;
        dfs(to, o, o, result);
    }
    rep (i, n) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}