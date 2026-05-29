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

    vector<vector<int>> A(n+1, vector<int>(n+1));
    rep (i, n) {
        rep (j, i+1) {
            int a;
            cin >> a;

            A[i+1][j+1] = a;
            A[j+1][i+1] = a;
        }
    }
    debug(A);

    int cs = 1;
    rep (i, n) {
        cs = A[cs][i+1];
    }

    cout << cs << '\n';

    return 0;
}