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

    int n, d;
    cin >> n >> d;

    vector<int> T(n), L(n);
    rep (i, n) {
        cin >> T[i] >> L[i];
    }

    for (int i=1; i!=d+1; ++i) {
        int max_weight = 0;
        rep (j, n) {
            max_weight = max(max_weight, T[j] * (L[j] + i));
        }
        cout << max_weight << '\n';
    }

    return 0;
}