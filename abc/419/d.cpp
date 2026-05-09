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
    string s, t;
    cin >> n >> m >> s >> t;

    vector<bool> change(n+1, false);
    rep (_, m) {
        int l, r;
        cin >> l >> r;
        l--;

        change[l] = !change[l];
        change[r] = !change[r];
    }

    bool is_t = false;
    rep (i, n) {
        if (change[i]) {
            is_t = !is_t;
        }
        if (is_t) {
            cout << t[i];
        }
        else {
            cout << s[i];
        }
    }
    cout << '\n';

    return 0;
}