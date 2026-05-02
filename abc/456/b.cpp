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

    vector<vector<float>> A(3, vector<float>(7, 0));
    rep (i, 3) {
        rep (j, 6) {
            int a;
            cin >> a;
            A[i][a]++;
        }
    }
    debug(A);

    float result = 0;
    result = A[0][4] * A[1][5] * A[2][6] + A[0][4] * A[1][6] * A[2][5] + A[0][5] * A[1][4] * A[2][6] + A[0][5] * A[1][6] * A[2][4] + A[0][6] * A[1][4] * A[2][5] + A[0][6] * A[1][5] * A[2][4];

    cout << setprecision(7) << result / 216 << '\n';

    return 0;
}