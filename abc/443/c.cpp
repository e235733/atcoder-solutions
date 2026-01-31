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

    int n, t;
    cin >> n >> t;
    int next_open = 0;
    int sum = 0;
    rep (_, n) {
        int a;
        cin >> a;
        if (a > next_open) {
            sum += a - next_open;
            next_open = min(a + 100, t);
        }
    }
    sum += t - next_open;

    cout << sum << endl;

    return 0;
}