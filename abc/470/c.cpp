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

    int n, q;
    cin >> n >> q;

    vector<int> A(n+1, 0);
    vector<int> idx;
    int ans = 0;

    rep (_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;

            if (A[x] == 0) idx.push_back(x);

            ans ^= A[x];
            ++A[x];
            ans ^= A[x];

            cout << ans << '\n';
        }
        else if (t == 2) {
            vector<int> nidx;
            for (int i : idx) {
                ans ^= A[i];
                --A[i];
                ans ^= A[i];

                if (A[i] != 0) nidx.push_back(i);
            }
            idx = nidx;

            cout << ans << '\n';
        }
    }

    return 0;
}