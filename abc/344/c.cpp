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

    int n, m, l;
    cin >> n;
    vector<int> A(n);
    rep (i, n) cin >> A[i];
    cin >> m;
    vector<int> B(m);
    rep (i, m) cin >> B[i];
    cin >> l;
    vector<int> C(l);
    rep (i, l) cin >> C[i];

    set<int> sum;
    rep (i, n) {
        rep (j, m) {
            rep (k, l) {
                sum.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    int q;
    cin >> q;
    rep (_, q) {
        int x;
        cin >> x;

        if (sum.contains(x)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}