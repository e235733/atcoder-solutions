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
    vector<int> pos(n+1);
    rep (i, n) {
        int p;
        cin >> p;
        pos[p] = i;
    }

    int q;
    cin >> q;
    rep (_, q) {
        int a, b;
        cin >> a >> b;
        if (pos[a] < pos[b]) cout << a << '\n';
        else cout << b << '\n';
    }

    return 0;
}