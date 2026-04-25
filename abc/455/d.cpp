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

    int n, q;
    cin >> n >> q;

    vector<int> up(n+1, -1);
    vector<int> down(n+1, -1);

    rep (_, q) {
        int c, p;
        cin >> c >> p;
        debug(c, p);

        if (down[c] == -1) {
            down[c] = p;
            up[p] = c;
        }
        else {
            up[down[c]] = -1;
            down[c] = p;
            up[p] = c;
        }
    debug(up);
    debug(down);
    }

    rep (i, n) {
        if (down[i+1] != -1) {
            cout << 0 << ' ';
            continue;
        }

        int count = 1;
        int next = up[i+1];
        while (next != -1) {
            count++;
            next = up[next];
        }
        cout << count << ' ';
    }
    cout << '\n';

    return 0;
}