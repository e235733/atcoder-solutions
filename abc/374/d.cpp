#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<pair<pair<double, double>, pair<double, double>>> &e, vector<int> &ord, int i, double cy, double cx, int n, double s, double t, double cc, double &mc) {
    debug(cy, cx, i);
    if (i == n) {
        mc = min(mc, cc);
        return;
    }

    auto [ny1, nx1] = e[ord[i]].first;
    auto [ny2, nx2] = e[ord[i]].second;
    
    double ct = sqrt((ny2 - ny1) * (ny2 - ny1) + (nx2 - nx1) * (nx2 - nx1)) / t;
    debug(ct);
    double dy1 = cy - ny1;
    double dx1 = cx - nx1;
    double dy2 = cy - ny2;
    double dx2 = cx - nx2;
    double cs1 = sqrt(dy1 * dy1 + dx1 * dx1) / s;
    double nc1 = cc + cs1 + ct;
    debug(ct, cs1, nc1);
    dfs (e, ord, i+1, ny2, nx2, n, s, t, nc1, mc);
    double cs2 = sqrt(dy2 * dy2 + dx2 * dx2) / s;
    double nc2 = cc + cs2 + ct;
    debug(ct, cs2, nc2);
    dfs (e, ord, i+1, ny1, nx1, n, s, t, nc2, mc);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    double s, t;
    cin >> n >> s >> t;

    vector<pair<pair<double, double>, pair<double, double>>> e(n);
    rep (i, n) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;

        e[i] = {{a, b}, {c, d}};
    }
    debug(e);

    vector<int> ord(n);
    rep (i, n) {
        ord[i] = i;
    }
    double mc = 1000000000;
    do {
        debug(ord);
        dfs(e, ord, 0, 0, 0, n, s, t, 0, mc);
    } while (next_permutation(ord.begin(), ord.end()));

    cout << setprecision(8) << mc << '\n';

    return 0;
}