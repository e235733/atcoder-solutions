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
    vector<string> S(n);
    rep (i, n) {
        cin >> S[i];
    }

    int pm = 0;
    vector<int> L(n);
    rep (i, n) {
        int len = S[i].size();
        if (len >= pm) {
            pm = len;
        }
        else {
            rep (j, pm-len) {
                S[i].push_back('*');
            }
        }
        L[i] = pm;
    }
    debug(S);
    debug(L);

    vector<string> T(pm);
    rep (i, n) {
        rep (j, L[n-i-1]) {
            T[j].push_back(S[n-i-1][j]);
        }
    }
    debug(T);

    rep (i, pm) {
        for (char c : T[i]) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}