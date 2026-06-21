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

    int n, a;
    cin >> n >> a;
    vector<int> T(n);
    rep (i, n) cin >> T[i];

    int pe = 0;
    rep (i, n) {
        pe = max(pe, T[i]);
        pe += a;
        cout << pe << '\n';
    }

    return 0;
}