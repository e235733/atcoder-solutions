#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

ll lcm(ll a, ll b) {
    ll la = a;
    ll lb = b;
    while (la != 0 && lb != 0) {
        if (la > lb) la %= lb;
        else lb %= la;
    }

    ll gcd = max(la, lb);

    return a * b / gcd;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ll n, m, k;
    cin >> n >> m >> k;

    ll ok = 1LL << 60;
    ll ng = 0;
    while (ng + 1 < ok) {
        ll mid = (ok + ng) / 2;
        ll p = mid / n + mid / m - mid / lcm(n, m) * 2;
        if (p >= k) ok = mid;
        else ng = mid;
    }

    cout << ok << '\n';

    return 0;
}