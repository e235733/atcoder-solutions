#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

map<ll, double> dp;

ll n, a;
double x, y;

double solve(ll m) {
    debug(m);
    if (m == 0) return 0;
    if (dp.contains(m)) return dp[m];

    double f1 = x + solve(m / a);
    double f2 = (y * 6 + solve(m/2) + solve(m/3) + solve(m/4) + solve(m/5) + solve(m/6)) / 5;

    dp[m] = min(f1, f2);
    return min(f1, f2);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> a >> x >> y;

    cout << setprecision(16) << solve(n) << '\n';

    return 0;
}