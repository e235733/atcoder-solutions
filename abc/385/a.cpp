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

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c) {
        cout << "Yes" << '\n';
        return 0;
    }

    if (a + b == c || a + c == b || b + c == a) {
        cout << "Yes" << '\n';
        return 0;
    }

    cout << "No" << '\n';

    return 0;
}