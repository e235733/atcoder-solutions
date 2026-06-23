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

    int n, l, r;
    cin >> n >> l >> r;

    for (int i=1; i!=l; ++i) cout << i << ' ';
    for (int i=r; i!=l-1; --i) cout << i << ' ';
    for (int i=r+1; i!=n+1; ++i) cout << i << ' ';
    cout << '\n';

    return 0;
}