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

    int a, b, c, x;
    cin >> a >> b >> c >> x;
    
    int count = 0;
    rep (i, a+1) {
        rep (j, b+1) {
            rep (k, c+1) {
                int value = 500 * i + 100 * j + 50 * k;
                debug(i, j, k, value);
                if (value == x) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}