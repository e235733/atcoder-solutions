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

    int n, c;
    cin >> n >> c;

    int prev_t = -1;
    int count = 0;
    rep (_, n) {
        int t;
        cin >> t;
        if (prev_t == -1) {
            count++;
            prev_t = t;
        }
        else {
            if (t - prev_t >= c) {
                count++;
                prev_t = t;
            }
        }
    }
    cout << count << '\n';

    return 0;
}