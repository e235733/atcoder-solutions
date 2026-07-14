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

    string S;
    cin >> S;

    int len = S.size();
    rep (i, len-1) {
        if (S[i] == 'B') {
            if (S[i+1] == 'A') {
                cout << "No" << '\n';
                return 0;
            }
        }
        else if (S[i] == 'C') {
            if (S[i+1] == 'A' || S[i+1] == 'B') {
                cout << "No" << '\n';
                return 0;
            }
        }
    }

    cout << "Yes" << '\n';

    return 0;
}