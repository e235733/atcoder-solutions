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

    map<int, int> ca;
    rep (i, n) {
        int a, c;
        cin >> a >> c;

        if (ca.contains(c)) {
            ca[c] = min(ca[c], a);
        }
        else ca[c] = a;
    }

    int ma = 0;
    for (auto [c, a] : ca) {
        ma = max(ma, a);
    }

    cout << ma << '\n';

    return 0;
}