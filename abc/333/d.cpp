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

    dsu uf(n);
    vector<int> vec;
    rep (_, n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        if (u == 0) {
            vec.push_back(v);
        }
        else {
            uf.merge(u, v);
        }
    }

    if (vec.size() == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int mb = 0;
    for (int a : vec) {
        mb = max(mb, uf.size(a));
    }

    cout << n - mb << '\n';

    return 0;
}