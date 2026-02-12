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

    int prev_a = -1;
    rep (i, 5) {
        int a;
        cin >> a;
        if (a == prev_a) {
            cout << "YES" << endl;
            return 0;
        }
        prev_a = a;
    }
    cout << "NO" << endl;

    return 0;
}