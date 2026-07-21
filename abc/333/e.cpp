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
    vector<int> T(n), X(n);
    rep (i, n) {
        cin >> T[n-i-1] >> X[n-i-1];
    }

    map<int, int> C;
    int mc = 0;
    int cc = 0;
    vector<bool> ans;

    rep (i, n) {
        if (T[i] == 1) {
            if (C.contains(X[i])) {
                --C[X[i]];
                if (C[X[i]] == 0) C.erase(X[i]);
                --cc;
                ans.push_back(1);
            }
            else {
                ans.push_back(0);
            }
        }
        else if (T[i] == 2) {
            ++C[X[i]];
            ++cc;
            mc = max(mc, cc);
        }
    }
    debug(C, mc, cc, ans);

    if (C.size()) {
        cout << -1 << '\n';
    }
    else {
        cout << mc << '\n';
        int len = ans.size();
        for (int i=len-1; i!=-1; --i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}