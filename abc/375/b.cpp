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

    int n;
    cin >> n;

    double result = 0;
    double p_x = 0;
    double p_y = 0;
    rep (i, n) {
        double x, y;
        cin >> x >> y;
        result += sqrt((x - p_x) * (x - p_x) + (y - p_y) * (y - p_y));
        p_x = x;
        p_y = y;
    }
    result += sqrt(p_x * p_x + p_y * p_y);
    cout << setprecision(32) << result << '\n';

    return 0;
}