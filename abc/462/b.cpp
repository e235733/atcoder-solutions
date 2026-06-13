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

    int n;
    cin >> n;
    vector<vector<int>> x(n+1);
    rep (i, n) {
        int k;
        cin >> k;

        rep (j, k) {
            int a;
            cin >> a;
            x[a].push_back(i+1);
        }        
    }
    debug(x);

    rep (i, n) {
        cout << x[i+1].size() << ' ';
        sort(x[i+1].begin(), x[i+1].end());
        for (int y : x[i+1]) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}