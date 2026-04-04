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

    set<pair<int, int>> gothec = {{1, 7}, {3, 3}, {5, 5}, {7, 7}, {9, 9}};

    int m, d;
    cin >> m >> d;

    if (gothec.contains({m, d})) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}