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

    int x, a, b;
    cin >> x >> a >> b;

    // 1
    x++;
    cout << x << endl;

    // 2
    x *= a + b;
    cout << x << endl;

    // 3
    x *= x;
    cout << x << endl;

    // 4
    x--;
    cout << x << endl;

    return 0;
}