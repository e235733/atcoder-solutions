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
    vector<vector<int>> vec(n);
    rep (i, n) {
        int l;
        cin >> l;

        vector<int> v(l);
        rep (j, l) {
            cin >> v[j];
        }

        vec[i] = v;
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    cout << vec[x][y] << '\n';

    return 0;
}