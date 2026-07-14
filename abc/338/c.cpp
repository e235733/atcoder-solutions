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
    cin >> n;
    vector<int> Q(n), A(n), B(n);
    rep (i, n) cin >> Q[i];
    rep (i, n) cin >> A[i];
    rep (i, n) cin >> B[i];

    vector<int> C;
    int  am = 0;
    while (true) {
        debug(am);
        bool ok = true;
        int bm = 1<<30;
        rep (i, n) {
            if (Q[i] < A[i] * am) {
                ok = false;
                break;
            }

            int pm = 1<<30;
            if (B[i] != 0) pm = (Q[i]-A[i]*am)/B[i];
            bm = min(bm, pm);
        }
        if (!ok) break;

        C.push_back(am + bm);
        ++am;
    }
    debug(C);

    cout << *max_element(C.begin(), C.end()) << '\n';

    return 0;
}