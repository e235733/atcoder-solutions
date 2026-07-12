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

    int q;
    cin >> q;
    vector<int> X;
    rep (_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            X.push_back(x);
        }
        else if (t == 2) {
            int k;
            cin >> k;
            int len = X.size();
            cout << X[len-k] << '\n';
        }
    }

    return 0;
}