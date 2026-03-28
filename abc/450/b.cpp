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

    vector<vector<int>> cost(n-1, vector<int>(n));
    rep (i, n) {
        for (int j=i+1; j!=n; ++j) {
            cin >> cost[i][j];
        }
    }
    debug(cost);

    rep (i, n-2) {
        int current_cost = 0;
        for (int j=i+1; j!=n-1; ++j) {
            current_cost += cost[i][j];

            for (int k=j+1; k!=n; ++k) {
                current_cost += cost[j][k];

                debug(i, j, k);
                debug(current_cost, cost[i][k]);

                if (current_cost < cost[i][k]) {
                    cout << "Yes" << '\n';
                    return 0;
                }

                current_cost -= cost[j][k];
            }
            current_cost = 0;
        }
    }

    cout << "No" << '\n';

    return 0;
}