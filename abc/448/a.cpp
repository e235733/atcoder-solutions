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

    int n, x;
    cin >> n >> x;

    rep (i, n) {
        int a;
        cin >> a;
        
        if (a < x) {
            x = a;
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}