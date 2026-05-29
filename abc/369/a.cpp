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

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 1 << '\n';
    }
    else if ((a - b) % 2 == 0) {
        cout << 3 << '\n';
    }
    else {
        cout << 2 << '\n' ;
    }

    return 0;
}