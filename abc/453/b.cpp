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

    int n, x;
    cin >> n >> x;

    int t = 0;
    int reg;
    cin >> reg;
    cout << t << ' ' << reg << '\n';

    rep (i, n) {
        int a;
        cin >> a;

        if (abs(a - reg) >= x) {
            reg = a;
            cout << i + 1 << ' ' << reg << '\n';
        }
    }

    return 0;
}