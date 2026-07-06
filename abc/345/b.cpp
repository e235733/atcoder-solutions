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

    ll n;
    cin >> n;

    if (n % 10 == 0 || n < 0) {
        cout << n / 10 << '\n';
    }
    else {
        cout << n / 10 + 1 << '\n';
    }

    return 0;
}