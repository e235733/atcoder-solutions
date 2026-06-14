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
    vector<double> L(n), R(n);
    rep (i, n) cin >> L[i] >> R[i];

    vector<vector<double>> cu(n, vector<double>(101, 0));
    rep (i, n) {
        for (int j=L[i]-1; j!=R[i]; ++j) {
            cu[i][j] = 1;
        }
        rep (j, 100) {
            cu[i][99-j] += cu[i][100-j];
        }
    }
    debug(cu);
    double result = 0;
    rep (i, n-1) {
        for (int j=i+1; j!=n; ++j) {
            double all = (R[i] - L[i] + 1) * (R[j] - L[j] + 1);
            double count = 0;
            for (int k=L[j]; k!=R[j]+1; ++k) {
                count += cu[i][k];
            }

            result += count / all;
        }
    }

    cout << setprecision(10) << result << '\n';

    return 0;
}