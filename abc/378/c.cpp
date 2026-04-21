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

    int n;
    cin >> n;

    map<int, int> m;
    rep (i, n) {
        int a;
        cin >> a;
        if (m.contains(a)) {
            cout << m[a] << '\n';
            m[a] = i + 1;
        }
        else {
            cout << -1 << '\n';
            m[a] = i + 1;
        }
    }

    return 0;
}