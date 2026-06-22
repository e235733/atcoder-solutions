#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

ll mod = 998244353;

ll n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n; 
    ll ln = n;
    mint p10d = 1;
    while (ln != 0) {
        p10d *= mint(10);
        ln /= 10;
    }

    mint ans = mint(n) * (p10d.pow(n) - mint(1)) * ((p10d - mint(1)).inv());
    cout << ans.val() << '\n';

    return 0;
}