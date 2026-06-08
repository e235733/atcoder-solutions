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
    cin >> n >> m;
    vector<string> s(n);
    rep (i, n) cin >> s[i];

    sort(s.begin(), s.end());
    debug(s);
    vector<vector<int>> B(m);
    B[0] = {n};
    rep (i, m-1) {
        int pb = 0;
        for (int b : B[i]) {
            if (s[pb][i] == '1') {
                B[i+1].push_back(b);
                continue;
            }

            for (int j=pb; j!=b; ++j) {
                if (s[j][i] == '1') {
                    B[i+1].push_back(j);
                    break;
                }
            }
            B[i+1].push_back(b);
            pb = b;
        }
    }
    debug(B);

    int pi = 0;
    for (int i : B[m-1]) {
        pi++;
        if (i == pi) {
            i--;
            cout << "Yes" << '\n';
            rep (j, m-1) {
                if (s[i][j] == '0') cout << '1';
                else cout << '0';
            }
            cout << s[i][m-1] << '\n';
            return 0;
        }
        pi = i;
    }

    cout << "No" << '\n';

    return 0;
}