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

    vector<int> C(m+1);
    rep (i, m) {
        cin >> C[i+1];
    }

    int result = 0;
    rep (i, n) {
        int a, b;
        cin >> a >> b;

        if (C[a] >= b) {
            result += b;
            C[a] -= b;
        }
        else {
            result += C[a];
            C[a] = 0;
        }
    }

    cout << result << '\n';

    return 0;
}