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

    vector<pair<int, int>> p(n);
    rep (i, n) {
        int a, b;
        cin >> a >> b;
        p[i] = {b, a};
    }

    sort(p.begin(), p.end());

    rep (i, n) {
        cout << p[i].second << ' ' << p[i].first << endl;
    }

    return 0;
}