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

    int h, w;
    cin >> h >> w;

    string edge_row = "";
    rep (i, w) {
        edge_row += '#';
    }
    cout << edge_row << '\n';

    string mid_row = "";
    mid_row += '#';
    rep (i, w-2) {
        mid_row += '.';
    }
    mid_row += '#';
    rep (i, h-2) {
        cout << mid_row << '\n';
    }

    cout << edge_row << '\n';

    return 0;
}