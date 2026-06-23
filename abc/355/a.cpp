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

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << -1 << '\n';
    }
    else {
        if (a != 1 && b != 1) cout << 1 << '\n';
        else if (a != 2 && b != 2) cout << 2 << '\n';
        else if (a != 3 && b != 3) cout << 3 << '\n';
    }

    return 0;
}