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

    int r, g, b;
    string c;
    cin >> r >> g >> b >> c;

    if (c == "Red") cout << min(g, b) << '\n';
    else if (c == "Green") cout << min(r, b) << '\n';
    else if (c == "Blue") cout << min(r, g) << '\n';

    return 0;
}