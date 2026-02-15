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
    debug(n, m);

    vector<vector<char>> result(n, vector<char>(n, '-'));
    rep (_, m) {
        int a, b;
        cin >> a >> b;
        debug(a, b);

        a--;
        b--;
        result[a][b] = 'o';
        result[b][a] = 'x';
    }

    rep (i, n) {
        rep (j, n) {
            cout << result[i][j];
            if (j != n - 1) {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}