#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int n, t;
vector<set<int>> R(1<<11), C(1<<11);
set<int> d1, d2;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> t;

    rep (i, t) {
        int a;
        cin >> a;
        a--;

        int r = a / n;
        int c = a % n;

        R[r].insert(a);
        C[c].insert(a);
        if ((int)R[r].size() == n || (int)C[c].size() == n) {
            cout << i + 1 << '\n';
            return 0;
        }

        if (r == c) {
            d1.insert(a);
            if ((int)d1.size() == n) {
                cout << i + 1 << '\n';
                return 0;
            }
        }

        if (r + c == n - 1) {
            d2.insert(a);
            if ((int)d2.size() == n) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}