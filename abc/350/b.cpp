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

    int n, q;
    cin >> n >> q;
    vector<bool> exist(n+1, true);

    rep (_, q) {
        int t;
        cin >> t;
        exist[t] = !exist[t];
    }

    int count = 0;
    rep (i, n) {
        if (exist[i+1]) count++;
    }

    cout << count << '\n';

    return 0;
}