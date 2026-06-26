#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (x < y) {
        if (x < z && z < y) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    else {
        if (y < z && z < x) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}