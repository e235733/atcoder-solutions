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

    int max_h = max(a, max(b, c));
    int min_h = min(a,  min(b, c));

    cout << max_h - min_h << endl;

    return 0;
}