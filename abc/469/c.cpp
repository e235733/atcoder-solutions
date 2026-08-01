#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    string S;
    cin >> n >> S;

    vector<int> so(n+1), sx(n+1);
    so[0] = 0, sx[0] = 0;

    rep (i, n) {
        if (S[i] == 'o') {
            so[i+1] = so[i] + 1;
            sx[i+1] = sx[i];
        }
        else {
            so[i+1] = so[i];
            sx[i+1] = sx[i] + 1;
        }
    }
    debug(so);
    debug(sx);

    rep (i, n) {
        int no = so[i+1];

        int ok = n;
        int ng = i;
        while (ng + 1 < ok) {
            int mid = (ok + ng) / 2;
            if (sx[mid] - sx[i+1] < no) {
                ng = mid;
            }
            else {
                ok = mid;
            }
        }

        cout << ok << '\n';
    }

    return 0;
}