#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    ll h;
    cin >> h;

    int i = 0;
    ll p = 0;
    ll g = 1;
    while (p <= h) {
        i++;
        p += g;
        g *= 2;
    }

    cout << i << '\n';

    return 0;
}