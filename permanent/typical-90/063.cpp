#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(int n, int k, int current, vector<int> comb, vector<vector<int>>& c_r) {
    if (comb.size() == k) {
        c_r.push_back(comb);
        return;
    }
    
    for (int i = current; i < n; ++i) {
        comb.push_back(i);
        dfs(n, k, i + 1, comb, c_r);
        comb.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w;
    cin >> h >> w;

    vector<vector<int>> p(h, vector<int>(w));
    rep (i, h) {
        rep (j, w) {
            cin >> p[i][j];
        }
    } 

    // r のすべての組み合わせ
    vector<vector<int>> c_r;
    rep (i, h) {
        dfs(h, i+1, 0, {}, c_r);
    }
    debug(c_r);

    int result = 0;
    for (auto c : c_r) {
        int size_c = c.size();
        unordered_map<int, int> count;
        rep (i, w) {
            vector<int> r(size_c);
            rep (j, size_c) {
                r[j] = p[c[j]][i];
            }
            debug(r);
            if (equal(r.begin() + 1, r.end(), r.begin())) {
                count[r[0]]++;
            }
        }
        int max_count = 0;
        for (auto d : count) {
            max_count = max(max_count, d.second);
        }
        debug(max_count);
        result = max(result, max_count * size_c);
    }
    cout << result << '\n';

    return 0;
}