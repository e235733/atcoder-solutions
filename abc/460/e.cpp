#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

u64 gcd (u64 a, u64 b) {
    if (max(a, b) % min(a, b) == 0) {
        return min(a, b);
    }

    return gcd(min(a, b), max(a, b) % min(a, b));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    u64 mod = 998244353;

    int t;
    cin >> t;
    rep (_, t) {
        u64 n, m;
        cin >> n >> m;

        u64 count = 0;

        u64 pp10 = 1;
        u64 cp10 = 10;
        while (pp10 <= n) {
            u64 l = pp10;
            u64 r = min(cp10, n + 1);
            u64 ne = (r - l) % mod;

            u64 g = gcd(cp10-1, m);
            debug(g);

            u64 cx = n / (m / g) % mod;
            count += ne * cx % mod;
            count %= 998244353;
            
            pp10 *= 10;
            cp10 *= 10;
        }

        cout << count << '\n';
    }

    return 0;
}