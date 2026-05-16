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

    int h, w;
    cin >> h >> w;

    rep (i, h) {
        rep (j, w) {
            int count = 4;
            if (i-1 < 0) {
                count--;
            }
            //debug(i-1, count);
            if (i+1 >= h) {
                count--;
            }
            //debug(i+1, count);
            if (j-1 < 0) {
                count--;
            }
            //debug(j-1, count);
            if (j+1 >= w) {
                count--;
            }
            //debug(j+1, count);
            cout << count << ' ';
        }
        cout << '\n';
    }

    return 0;
}