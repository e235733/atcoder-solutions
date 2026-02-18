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

    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    debug(A);

    int head = 0;
    rep (_, q) {
        int t, x, y;
        cin >> t >> x >> y;
        debug(t, x, y);
        x = (head + x - 1) % n;
        y = (head + y - 1) % n;
        debug(x, y);
        if (t == 1) {
            int r = A[x];
            A[x] = A[y];
            A[y] = r;
            debug(A);
        }
        else if (t == 2) {
            head = (head + n - 1) % n;
        }
        else {
            cout << A[x] << '\n';
        }
        debug(head);
    }

    return 0;
}