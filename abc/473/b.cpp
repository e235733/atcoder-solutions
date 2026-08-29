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

    int n;
    cin >> n;

    map<int, int> A;
    rep (i, n) {
        int a;
        cin >> a;
        ++A[a];
    }

    int ans = 0;
    for (auto [a, c] : A) {
        if (c % 2 == 1) ans += a;
    }

    cout << ans << '\n';

    return 0;
}