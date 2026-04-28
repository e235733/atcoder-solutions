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

    int n, m;
    cin >> n >> m;

    vector<int> d_r = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> d_c = {1, 2, 2, 1, -1, -2, -2, -1};

    set<pair<int, int>> ng;
    rep (_, m) {
        int a, b;
        cin >> a >> b;

        ng.insert({a, b});
        rep (i, 8) {
            int r = a + d_r[i];
            int c = b + d_c[i];
            if (r < 1 || r > n || c < 1 || c > n) {
                continue;
            }

            ng.insert({r, c});
        }
    }

    cout << 1LL * n * n - ng.size() << '\n';

    return 0;
}