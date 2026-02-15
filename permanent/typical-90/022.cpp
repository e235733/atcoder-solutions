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

    ll a, b, c;
    cin >> a >> b >> c;
    debug(a, b, c);

    // ユークリッドの互除法で最大公約数を求める
    // a と b の最大公約数を求める
    ll d = a;
    ll e = b;
    while (d != 0 && e != 0) {
        if (d > e) {
            d %= e;
        }
        else {
            e %= d;
        }
    }
    ll f = max(d, e);
    debug(f);
    ll g = c;
    // 結果と c の最大公約数を求める
    while (f != 0 && g != 0) {
        if (f > g) {
            f %= g;
        }
        else {
            g %= f;
        }
    }
    ll h = max(g, f);
    debug(h);

    // すべての次元を h でわる
    ll result = a / h + b / h + c / h - 3;
    cout << result << endl;

    return 0;
}