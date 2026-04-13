#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(int n, int m, vector<int> vec, vector<vector<int>>& result) {
    debug(vec);
    int length = vec.size();

    if (length == n) {
        result.push_back(vec);
    }
    else if (length == 0){
        int max_val = m - (n - 1) * 10;
        for (int i=1; i!=max_val+1; ++i) {
            vec.push_back(i);
            dfs(n, m, vec, result);
            vec.pop_back();
        }
    }
    else {
        int max_val = m - (n - length - 1) * 10;
        for (int i=vec.back()+10; i!=max_val+1; ++i) {
            vec.push_back(i);
            dfs(n, m, vec, result);
            vec.pop_back();
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

    vector<int> vec;
    vec.reserve(n);
    vector<vector<int>> result;
    dfs(n, m, vec, result);

    int num_result = result.size();
    cout << num_result << '\n';
    
    rep (i, num_result) {
        rep (j, n) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}